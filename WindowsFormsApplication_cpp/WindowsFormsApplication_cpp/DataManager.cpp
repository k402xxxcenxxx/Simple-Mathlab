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
		while (fin >> tempString)
		{

			//從檔案讀取字串
			//fin >> tempString;
			
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

				std::cout << "vector [" << VectorVariableIndex << "]" <<"pushback value ("<< value<< ")" << std::endl;
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
		tempVectorData.clear();
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
		Vector tempVector;
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
					
					//已經蒐集好的行加入最後結果
					tempVector.setName("$m" + std::to_string(MatrixVariableIndex) + "[" + std::to_string(tempMatrixRowIndex) + "]");
					tempMatrixData.push_back(tempVector);

					//Row數目增加
					tempMatrixRowIndex++;

					tempVector.clear();
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
					tempVector.clear();

					tempMatrixColIndex = 0;
					tempMatrixRowIndex = 0;
				}
				//遞增currentLoadMatrixID，標記到當前讀取矩陣ID
				currentLoadMatrixID++;
				//從檔案讀取字串，取得矩陣維度
				fin >> tempString;
				tempMatrixRowNum = (int)strtod(tempString.c_str(), NULL);

				fin >> tempString;
				tempMatrixColNum = (int)strtod(tempString.c_str(), NULL);

				tempMatrixColNum = tempMatrixColNum;

				tempMatrixRowNum = tempMatrixRowNum;
			}
			else
			{
				
				//如果column大於原先設定則代表換行了
				if (tempMatrixColIndex >= tempMatrixColNum) {
					
					//已經蒐集好的行加入最後結果
					tempVector.setName("$m" + std::to_string(MatrixVariableIndex) + "[" + std::to_string(tempMatrixRowIndex) + "]");
					tempMatrixData.push_back(tempVector);

					//Row數目增加
					tempMatrixRowIndex++;
					int num = tempMatrixData.size();
					num = num;
					tempVector.clear();
					//設定為零
					tempMatrixColIndex = 0;
				}

				//讀取矩陣資料，並將string轉為double
				double value;
				value = (double)strtod(tempString.c_str(), NULL);
				//將矩陣資料存入暫存
				tempVector.push_back(value);
				//新增一個column
				tempMatrixColIndex++;

			}

		}

		//Row數目增加
		tempMatrixRowIndex++;
		//已經蒐集好的行加入最後結果
		tempMatrixData.push_back(tempVector);
		tempVector.clear();
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
		outputTemp += scalarString.substr(0, scalarString.size());
		if (j != getData().size() - 1)
			outputTemp += ",";
	}
	//將輸出格式存入暫存，並且換行
	outputTemp += "]";

	return outputTemp;
}
double Vector::com(Vector V1, Vector V2) {
	double result = 0;
	double length = Vector::norm(V2);
	double dot = Vector::dot(V1, V2);


	result = dot / length;//How to call the"dot" in another function?
	return result;

}
Vector Vector::proj(Vector V1, Vector V2) {

	Vector result;

	std::vector<double> tem;
	double length = Vector::norm(V2);
	double com = Vector::com(V1, V2);
	for (int i = 0; i < V1.getData()[i]; i++) {
		tem.push_back(V2.getData()[i] * com / length);
	}

	result.setData(tem);
	return result;

}
bool Vector::paralell(Vector V1, Vector V2) {
	bool result = true;
	for (int i = V1.getData().size(); i = 0; i--) {
		if (V1.getData()[i] / V2.getData()[i] != V1.getData()[i - 1] / V2.getData()[i - 1]) {
			result = false;
			break;
		}

	}
	return result;
}
double Vector::dot(Vector V1, Vector V2) {
	double result = 0;
	for (int i = 0; i < V1.getData().size(); i++) {
		result += V1.getData()[i] * V2.getData()[i];
	}

	return result;
}

Vector Vector::add(Vector V1, Vector V2, bool testTinyValue) {
	Vector result;

	std::vector<double> tempVector;
	for (int i = 0; i < V1.getData().size(); i++) {

		if (std::abs(V1.getData()[i] + V2.getData()[i]) < 1e-8 && testTinyValue)
			tempVector.push_back(0);
		else
			tempVector.push_back(V1.getData()[i] + V2.getData()[i]);
	}

	result.setData(tempVector);
	return result;
}

Vector Vector::sub(Vector V1, Vector V2, bool testTinyValue) {
	Vector result;

	std::vector<double> tempVector;
	for (int i = 0; i < V1.getData().size(); i++) {

		if (std::abs(V1.getData()[i] - V2.getData()[i]) < 1e-8 && testTinyValue)
			tempVector.push_back(0);
		else
			tempVector.push_back(V1.getData()[i] - V2.getData()[i]);
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

bool Vector::isOrthogonal(Vector V1, Vector V2) {
	//Two nonzero vectors a and b are orthogonal if and only if a dot b = 0.

	return Vector::dot(V1, V2) == 0;
}

Vector Vector::crossProduct(Vector V1, Vector V2) {
	Vector result;
	std::vector<double> tempVector;
	
	tempVector.push_back(V1.getData()[1] * V2.getData()[2] - V1.getData()[2] * V2.getData()[1]);
	tempVector.push_back(-1 * ( V1.getData()[0] * V2.getData()[2] - V1.getData()[2] * V2.getData()[0] ));
	tempVector.push_back(V1.getData()[0] * V2.getData()[1] - V1.getData()[1] * V2.getData()[0]);
	
	result.setData(tempVector);

	return result;
}

Vector Vector::planeNormal(Vector V1, Vector V2) {
	return crossProduct(V1, V2);
}

double Vector::angle(Vector V1, Vector V2) {
	double cosValue = Vector::dot(V1, V2) / (Vector::norm(V1) * Vector::norm(V2));
	double result = acos(cosValue);
	
	result = result / 3.1415926 * 180;

	return result;
}

double Vector::determine_slow(std::vector<Vector> Vs,int n) {
	double result = 0;

	if (n == 2) {
		//ad - bc
		double a = Vs[0].getData()[0];
		double b = Vs[0].getData()[1];
		double c = Vs[1].getData()[0];
		double d = Vs[1].getData()[1];
		result = a*d - b*c;
	}
	else {
		std::vector<Vector> newVs;
		Vector newV;

		//計算每個位置的determine，加總
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
			{
				//基礎值
				double base = Vs[i].getData()[j];
				//std::cout << "base["<<i<<"]["<<j<<"] = " << Vs[i].getData()[j] << std::endl;
				//std::cout << "matrix[" << i << "][" << j << "] = "<<std::endl;
				//建立小一階的矩陣
				for (int ii = 0; ii < n; ii++) {
					//同row不算
					if (ii != i) {
						for (int jj = 0; jj < n; jj++) {
							//同column不算
							if (jj != j) {
								//std::cout << Vs[ii].getData()[jj] << " ";
								newV.push_back(Vs[ii].getData()[jj]);
							}

						}
						//std::cout <<std::endl;
						//一row存完、push進去
						newVs.push_back(newV);
						newV.clear();
					}
				}

				//取得下一階determine
				if((i * n + j) % 2 == 0)
					result += base * -1 * Vector::determine(newVs, n - 1);
				else
					result += base * Vector::determine(newVs, n - 1);
				newVs.clear();
			}
		}
	}

	return result;
}

double Vector::determine(std::vector<Vector> Vs, int n) {
	double result = 1;

	//消成上三角
	//對每一個做
	for (int i = 0; i < n; i++) {
		//要乘以的係數的基數
		double base = Vs[i].getData()[i];

		//向其下面的row做系數相減，使得最前面的係數為0
		for (int j = i + 1; j < n; j++) {
			//row要乘以的倍數
			double scale = Vs[j].getData()[i] / base;
			//乘以倍數之後相減
			Vs[j] = Vector::add(Vs[j],Vector::scale(Vs[i], -1 * scale));
		}
	}

	//做完就可以用斜角相乘，得到determine
	for (int i = 0; i < n; i++) {
		result *= Vs[i].getData()[i];
	}

	return result;
}

std::vector<Vector> Vector::basis(std::vector<Vector> Vs, int n) {
	std::vector<Vector> result;

	//首先，第一個向量不用算
	//不過順手正規化
	result.push_back(Vector::normalization(Vs[0]));

	//接下來每個向量都跟前面向量做處理
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			//前面的向量
			Vector tempV = Vs[j];
			//上一個向量乘上dot除以長度
			//因為等一下要做相減，所以乘上-1
			tempV = Vector::scale(tempV, -1 * Vector::dot(Vs[i], tempV) / Vector::dot(tempV, tempV));
			Vs[i] = Vector::add(Vs[i], tempV);
		}

		result.push_back(Vector::normalization(Vs[i]));
	}

	return result;
}

//-------------------------------------------------------------------------------------------------------------------------------------------
//matrix
//-------------------------------------------------------------------------------------------------------------------------------------------

std::string Matrix::print() {
	std::string outputTemp = " [";
	//將輸出資料存入暫存
	for (int j = 0; j < getrowNum(); j++)
	{
		outputTemp += " [";
		for (int k = 0; k < getcolNum(); k++)
		{
			std::string scalarString = std::to_string(getData()[j].getData()[k]);
			outputTemp += scalarString.substr(0, scalarString.size());
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

Matrix Matrix::add(Matrix M1, Matrix M2, bool testTinyValue) {
	Matrix result;
	Vector tempV;

	result.setrowNum(M1.getrowNum());
	result.setcolNum(M1.getcolNum());

	for (int i = 0; i < M1.getrowNum(); i++) {
		tempV = Vector::add(M1.getData()[i], M2.getData()[i], testTinyValue);
		result.push_back(tempV);
	}
	return result;
}

Matrix Matrix::sub(Matrix M1, Matrix M2, bool testTinyValue) {
	Matrix result;
	Vector tempV;

	result.setrowNum(M1.getrowNum());
	result.setcolNum(M1.getcolNum());

	for (int i = 0; i < M1.getrowNum(); i++) {
		tempV = Vector::sub(M1.getData()[i], M2.getData()[i], testTinyValue);
		result.push_back(tempV);
	}
	return result;
}

Matrix Matrix::multi(Matrix M1, Matrix M2) {
	Matrix result;
	Vector tempV;
	//a*b x b*c = a*c
	result.setrowNum(M1.getrowNum());
	result.setcolNum(M2.getcolNum());

	//對最後結果要的每格作取值
	//做每個row
	for (int i = 0; i < M1.getrowNum(); i++) {
		//做每個Col
		for (int j = 0; j < M2.getcolNum(); j++) {
			double value = 0;

			//每個col都相乘
			for (int col = 0; col < M1.getcolNum(); col++) {
				value += M1.getData()[i].getData()[col] * M2.getData()[col].getData()[j];
			}

			tempV.push_back(value);
		}
		//一個row做完就push
		result.push_back(tempV);
		tempV.clear();
	}

	return result;
}

Matrix Matrix::row_echelon(Matrix M) {
	int colNum = M.getcolNum();
	int rowNum = M.getrowNum();
	//由上做到下
	for (int i = 0; i < rowNum; i++) {
		//要乘以的係數的基數
		double base = M.getData()[i].getData()[i];
		std::cout << "base = " << base << std::endl;
		//如果base是0，就換到最下面，檢查是否可以做
		//測試次數，如果到底都沒有非零的數也要停下
		int testTime = 1;
		while (base == 0 && testTime + i < rowNum)
		{
			base = M.getData()[testTime + i].getData()[i];
			std::cout << " base = " << base << std::endl;
			testTime++;
		}

		if (testTime > 1) {
			M.swapRow(i, testTime - 1 + i);
			//如果有交換，要乘-1
			M.getData()[i] = Vector::scale(M.getData()[i], -1);
		}

		if (base != 0) {
			//向其下面的row做系數相減，使得最前面的係數為0
			for (int j = i + 1; j < rowNum; j++) {
				//row要乘以的倍數
				double scale = M.getData()[j].getData()[i] / base;
				std::cout << "--scale["<<j<<"]["<<i<<"] = " << scale << std::endl;
				Vector scaled = Vector::scale(M.getData()[i], scale);

				//乘以倍數之後相減
				M.setDataAt(Vector::sub(M.getData()[j], scaled, true), j);
			}
		}
	}

	for (int i = 0; i < rowNum; i++) {
		std::cout << "[";
		for (int j = 0; j < colNum; j++) {
			std::cout << M.getData()[i].getData()[j];
			if (j != colNum - 1) {
				std::cout << ",";
			}
		}
		std::cout << "]";
		if (i != rowNum - 1) {
			std::cout << "," << std::endl;
		}
	}

	return M;
}

int Matrix::rank(Matrix M) {
	int result = M.getrowNum();

	int colNum = M.getcolNum();
	int rowNum = M.getrowNum();

	//改成上三角矩陣
	M = Matrix::row_echelon(M);
	//檢查是否一整個row為0
	bool zeroRow = true;

	for (int i = rowNum - 1; i >= 0; i--) {
		for (int j = colNum - 1; j >= 0; j--) {
			//只要掃到一個row不是零，就不用再掃了
			if (M.getData()[i].getData()[j] != 0) {
				zeroRow = false;
				break;
			}
		}
		if (zeroRow) {
			result -= 1;
		}
		else {
			//只要掃到一個row不是零，就不用再掃了
			break;
		}
	}

	return result;
}

Matrix Matrix::transpose(Matrix M) {
	Matrix tempM;
	Vector tempV;

	int colNum = M.getrowNum();
	int rowNum = M.getcolNum();

	//由上做到下
	//存結果
	for (int i = 0; i < rowNum; i++) {
		for (int j = 0; j < colNum; j++) {
			tempV.push_back(M.getData()[j].getData()[i]);
		}
		tempM.push_back(tempV);
		tempV.clear();
	}

	tempM.setcolNum(colNum);
	tempM.setrowNum(rowNum);
	return tempM;
}

double Matrix::determine(Matrix M, int n) {
	double result = 1;
	//消成上三角
	//對每一個做

	M = Matrix::row_echelon(M);

	//做完就可以用斜角相乘，得到determine
	for (int i = 0; i < n; i++) {
		result *= M.getData()[i].getData()[i];
	}

	return result;
}

Matrix Matrix::adjoint(Matrix M,int n) {
	int colNum = M.getrowNum();
	int rowNum = M.getcolNum();
	Matrix resultM;
	Vector resultTempV;
	Matrix tempM;//降階的Matrix
	Vector tempV;

	//計算每個位置的determine
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			//取得降階Mtrix
			for (int ii = 0; ii < n; ii++) {
				//同row不算
				if (ii != i) {
					for (int jj = 0; jj < n; jj++) {
						//同column不算
						if (jj != j) {
							tempV.push_back(tempM.getData()[ii].getData()[jj]);
						}

					}
					//一row存完、push進去
					tempM.push_back(tempV);
					tempV.clear();
				}
			}

			resultTempV.push_back(Matrix::determine(tempM,n-1));
			
		}

		resultM.push_back(resultTempV);
		resultTempV.clear();
	}

	return resultM;
}

Matrix Matrix::inverse_matrix(Matrix M,int n) {
	Matrix resultM;
	Vector resultTempV;

	double det = Matrix::determine(M, n);

	if (det == 0) {
		return ;
	}

	resultM = Matrix::adjoint(M, n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			resultM.setDataAt(1 / det * resultM.get(i,j) , i , j);
		}
	}

	resultM = Matrix::transpose(resultM);

	return resultM;
}