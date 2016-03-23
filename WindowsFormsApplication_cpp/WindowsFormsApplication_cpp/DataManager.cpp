#include"DataManager.h"

DataManager::DataManager()
{
	VectorVariableIndex = 0;
	MatrixVariableIndex = 0;
}

bool DataManager::LoadVectorData()
{
	std::fstream fin;
	//開啟檔案，傳入open函數的參數有兩個，欲開起的檔案名稱，開啟檔案的模式參數(這邊std::ios::in為讀取(輸入)狀態)
	fin.open(FileName, std::ios::in);
	//讀取失敗回傳false
	if (!fin)
	{
		return false;
	}
	else
	{
		//標記當前讀取向量ID
		int currentLoadVectorID = 0;
		//定義向量資料暫存變數
		std::vector<double> tempVectorData;
		//定義讀取檔案字串暫存變數
		std::string tempString;
		//從檔案讀取字串，解析掉向量總數
		fin >> tempString;
		
		//執行讀檔迴圈，並在讀到檔案結尾時結束
		while (!fin.eof())
		{
			//從檔案讀取字串
			fin >> tempString;
			//解析到向量標記"V"
			if (tempString == "V")
			{
				if (currentLoadVectorID != 0)
				{
					//定義暫存向量資料結構
					Vector tempVector;
					//存入向量資料
					tempVector.setData(tempVectorData);
					//定義向量變數名稱，依VectorVariableIndex變數作名稱的控管
					std::string vectorVariableTemp = "$v" + std::to_string(VectorVariableIndex);
					//存入向量變數名稱
					tempVector.setName(vectorVariableTemp);
					//存入向量
					Vectors.push_back(tempVector);
					//遞增VectorVariableIndex，以確保變數名稱不重複
					VectorVariableIndex++;
					//清除向量資料暫存
					tempVectorData.clear();
				}
				//遞增currentLoadVectorID，標記到當前讀取向量ID
				currentLoadVectorID++;
				//從檔案讀取字串，解析掉向量維度
				fin >> tempString;
			}
			else
			{
				//讀取向量資料，並將string轉為double
				double value;
				value = (double)strtod(tempString.c_str(), NULL);
				//將向量資料存入暫存
				tempVectorData.push_back(value);
			}
			
		}
		//讀入輸入檔案中最後一個向量資訊
		Vector tempVector;
		tempVector.setData(tempVectorData);
		std::string vectorVariableTemp = "$v" + std::to_string(VectorVariableIndex);
		tempVector.setName(vectorVariableTemp);
		Vectors.push_back(tempVector);
		VectorVariableIndex++;
		//讀取成功回傳false
		return true;
	}
}

std::vector<Vector> DataManager::GetVectors()
{
	return Vectors;
}

bool DataManager::LoadMatrixData()
{
	std::fstream fin;
	//開啟檔案，傳入open函數的參數有兩個，欲開起的檔案名稱，開啟檔案的模式參數(這邊std::ios::in為讀取(輸入)狀態)
	fin.open(FileName, std::ios::in);
	//讀取失敗回傳false
	if (!fin)
	{
		return false;
	}
	else
	{
		//標記當前讀取矩陣ID
		int currentLoadMatrixID = 0;
		int inputMatrixCount = 0;
		//定義矩陣資料暫存變數
		std::vector<Vector> tempMatrixData;
		//定義矩陣資料暫存Row
		Vector tempValues;
		//定義矩陣暫存column數量
		int tempMatrixColNum = 0;
		//定義矩陣暫存第N個column
		int tempMatrixColIndex = 0;
		//定義矩陣暫存row數量
		int tempMatrixRowNum = 0;
		//定義矩陣暫存第N個row
		int tempMatrixRowIndex = 0;
		//定義讀取檔案字串暫存變數
		std::string tempString;
		//從檔案讀取字串，取得矩陣總數
		fin >> tempString;
		inputMatrixCount = (int)strtod(tempString.c_str(), NULL);

		//執行讀檔迴圈，並在讀到檔案結尾時結束，或是讀到指定數量的矩陣後結束
		while (!fin.eof())
		{
			//從檔案讀取字串
			fin >> tempString;
			//解析到矩陣標記"M"，如果不是開頭的話，代表是讀完一個矩陣了，要把暫存的矩陣存起來
			if (tempString == "M")
			{
				if (currentLoadMatrixID != 0)
				{
					//Row數目增加
					tempMatrixRowIndex++;
					//已經蒐集好的行加入最後結果
					tempMatrixData.push_back(tempValues);
					tempValues.getData().clear();
					//設定為零
					tempMatrixColIndex = 0;

					//定義暫存矩陣資料結構
					Matrix tempMatrix;
					//存入矩陣資料
					tempMatrix.setData(tempMatrixData);
					//定義矩陣變數名稱，依MatrixVariableIndex變數作名稱的控管
					std::string matrixVariableTemp = "$m" + std::to_string(MatrixVariableIndex);
					//存入矩陣變數名稱
					tempMatrix.setName(matrixVariableTemp);
					//存入矩陣
					Matrices.push_back(tempMatrix);

					Matrices[MatrixVariableIndex].setcolNum(tempMatrixColNum);
					Matrices[MatrixVariableIndex].setrowNum(tempMatrixRowNum);
					//遞增MatrixVariableIndex，以確保變數名稱不重複
					MatrixVariableIndex++;
					//清除矩陣資料暫存
					tempMatrixData.clear();
					tempValues.getData().clear();

					tempMatrixColIndex = 0;
					tempMatrixRowIndex = 0;
				}
				//遞增currentLoadMatrixID，標記到當前讀取矩陣ID
				currentLoadMatrixID++;
				//從檔案讀取字串，取得矩陣維度
				fin >> tempString;
				tempMatrixColNum = (int)strtod(tempString.c_str(), NULL);

				fin >> tempString;
				tempMatrixRowNum = (int)strtod(tempString.c_str(), NULL);
			}
			else
			{
				
				//如果column大於原先設定則代表換行了
				if (tempMatrixColIndex >= tempMatrixColNum) {
					//Row數目增加
					tempMatrixRowIndex++;
					//已經蒐集好的行加入最後結果
					tempMatrixData.push_back(tempValues);
					tempValues.getData().clear();
					//設定為零
					tempMatrixColIndex = 0;
				}

				//讀取矩陣資料，並將string轉為double
				double value;
				value = (double)strtod(tempString.c_str(), NULL);
				//將矩陣資料存入暫存
				tempValues.getData().push_back(value);
				//新增一個column
				tempMatrixColIndex++;

			}

		}

		//Row數目增加
		tempMatrixRowIndex++;
		//已經蒐集好的行加入最後結果
		tempMatrixData.push_back(tempValues);
		tempValues.getData().clear();
		//設定為零
		tempMatrixColIndex = 0;

		//讀入輸入檔案中最後一個向量資訊
		Matrix tempMatrix;
		tempMatrix.setData(tempMatrixData);
		std::string matrixVariableTemp = "$m" + std::to_string(MatrixVariableIndex);
		tempMatrix.setName(matrixVariableTemp);
		tempMatrix.setcolNum(tempMatrixColNum);
		tempMatrix.setrowNum(tempMatrixRowNum);
		Matrices.push_back(tempMatrix);

		int num = tempMatrix.getrowNum();

		MatrixVariableIndex++;
		//讀取成功回傳false
		return true;
	}
}

std::vector<Matrix> DataManager::GetMatrices()
{
	return Matrices;
}

void DataManager::SetFileName(std::string fileName)
{
	FileName = fileName;
}

std::string Vector::print() {
	//將輸出格式存入暫存
	std::string outputTemp = "[";
	//將輸出資料存入暫存
	for (unsigned int j = 0; j < getData().size(); j++)
	{
		std::string scalarString = std::to_string(getData()[j]);
		outputTemp += scalarString.substr(0, scalarString.size() - 5);
		if (j != getData().size() - 1)
			outputTemp += ",";
	}
	//將輸出格式存入暫存，並且換行
	outputTemp += "]";

	return outputTemp;
}

double Vector::dot(Vector V1, Vector V2) {
	double result = 0;
	for (int i = 0; i < V1.getData().size(); i++) {
		result += V1.getData()[i] * V2.getData()[i];
	}

	return result;
}

Vector Vector::add(Vector V1, Vector V2) {
	Vector result;

	std::vector<double> tempVector;
	for (int i = 0; i < V1.getData().size(); i++) {
		tempVector.push_back(V1.getData()[i] + V2.getData()[i]);
	}

	result.setData(tempVector);
	return result;
}

Vector Vector::scale(Vector V, double value) {
	Vector result;

	std::vector<double> tempVector;
	for (int i = 0; i < V.getData().size(); i++) {
		tempVector.push_back(V.getData()[i] * value);
	}

	result.setData(tempVector);
	return result;
}

double Vector::norm(Vector V) {
	double result = 0;
	for (int i = 0; i < V.getData().size(); i++) {
		result += V.getData()[i] * V.getData()[i];
	}

	result = sqrt(result);

	return result;
};

Vector Vector::normalization(Vector V) {
	double norm = 1 / Vector::norm(V);
	Vector result = Vector::scale(V,norm);

	return result;
}

std::string Matrix::print() {
	std::string outputTemp = " [";
	//將輸出資料存入暫存
	for (int j = 0; j < getrowNum(); j++)
	{
		outputTemp += " [";
		for (int k = 0; k < getcolNum(); k++)
		{
			std::string scalarString = std::to_string(getData()[j].getData()[k]);
			outputTemp += scalarString.substr(0, scalarString.size() - 5);
			if (k != getcolNum() - 1)
				outputTemp += ",";
		}
		outputTemp += "]";
		outputTemp += "\n";

		if (j != getrowNum() - 1)
			outputTemp += ",";
	}
	//將輸出格式存入暫存，並且換行
	outputTemp += "]\n";

	return outputTemp;
}


