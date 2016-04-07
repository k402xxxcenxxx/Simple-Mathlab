#include"DataManager.h"

DataManager::DataManager()
{
	VectorVariableIndex = 0;
	MatrixVariableIndex = 0;
}

bool DataManager::LoadVectorData()
{
	std::fstream fin;
	//�}���ɮסA�ǤJopen��ƪ��ѼƦ���ӡA���}�_���ɮצW�١A�}���ɮת��Ҧ��Ѽ�(�o��std::ios::in��Ū��(��J)���A)
	fin.open(FileName, std::ios::in);
	//Ū�����Ѧ^��false
	if (!fin)
	{
		return false;
	}
	else
	{
		//�аO��eŪ���V�qID
		int currentLoadVectorID = 0;
		//�w�q�V�q��ƼȦs�ܼ�
		std::vector<double> tempVectorData;
		//�w�qŪ���ɮצr��Ȧs�ܼ�
		std::string tempString;
		//�q�ɮ�Ū���r��A�ѪR���V�q�`��
		fin >> tempString;
		
		//����Ū�ɰj��A�æbŪ���ɮ׵����ɵ���
		while (fin >> tempString)
		{

			//�q�ɮ�Ū���r��
			//fin >> tempString;
			
			//�ѪR��V�q�аO"V"
			if (tempString == "V")
			{
				if (currentLoadVectorID != 0)
				{
					//�w�q�Ȧs�V�q��Ƶ��c
					Vector tempVector;
					//�s�J�V�q���
					tempVector.setData(tempVectorData);
					//�w�q�V�q�ܼƦW�١A��VectorVariableIndex�ܼƧ@�W�٪�����
					std::string vectorVariableTemp = "$v" + std::to_string(VectorVariableIndex);
					//�s�J�V�q�ܼƦW��
					tempVector.setName(vectorVariableTemp);
					//�s�J�V�q
					Vectors.push_back(tempVector);
					//���WVectorVariableIndex�A�H�T�O�ܼƦW�٤�����
					VectorVariableIndex++;
					//�M���V�q��ƼȦs
					tempVectorData.clear();
				}
				//���WcurrentLoadVectorID�A�аO���eŪ���V�qID
				currentLoadVectorID++;
				//�q�ɮ�Ū���r��A�ѪR���V�q����
				fin >> tempString;
			}
			else 
			{
				//Ū���V�q��ơA�ñNstring�ରdouble
				double value;
				value = (double)strtod(tempString.c_str(), NULL);
				//�N�V�q��Ʀs�J�Ȧs

				std::cout << "vector [" << VectorVariableIndex << "]" <<"pushback value ("<< value<< ")" << std::endl;
				tempVectorData.push_back(value);

			}
			
		}
		//Ū�J��J�ɮפ��̫�@�ӦV�q��T
		Vector tempVector;
		tempVector.setData(tempVectorData);
		std::string vectorVariableTemp = "$v" + std::to_string(VectorVariableIndex);
		tempVector.setName(vectorVariableTemp);
		Vectors.push_back(tempVector);
		VectorVariableIndex++;
		tempVectorData.clear();
		//Ū�����\�^��false
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
	//�}���ɮסA�ǤJopen��ƪ��ѼƦ���ӡA���}�_���ɮצW�١A�}���ɮת��Ҧ��Ѽ�(�o��std::ios::in��Ū��(��J)���A)
	fin.open(FileName, std::ios::in);
	//Ū�����Ѧ^��false
	if (!fin)
	{
		return false;
	}
	else
	{
		//�аO��eŪ���x�}ID
		int currentLoadMatrixID = 0;
		int inputMatrixCount = 0;
		//�w�q�x�}��ƼȦs�ܼ�
		std::vector<Vector> tempMatrixData;
		//�w�q�x�}��ƼȦsRow
		Vector tempVector;
		//�w�q�x�}�Ȧscolumn�ƶq
		int tempMatrixColNum = 0;
		//�w�q�x�}�Ȧs��N��column
		int tempMatrixColIndex = 0;
		//�w�q�x�}�Ȧsrow�ƶq
		int tempMatrixRowNum = 0;
		//�w�q�x�}�Ȧs��N��row
		int tempMatrixRowIndex = 0;
		//�w�qŪ���ɮצr��Ȧs�ܼ�
		std::string tempString;
		//�q�ɮ�Ū���r��A���o�x�}�`��
		fin >> tempString;
		inputMatrixCount = (int)strtod(tempString.c_str(), NULL);

		//����Ū�ɰj��A�æbŪ���ɮ׵����ɵ����A�άOŪ����w�ƶq���x�}�ᵲ��
		while (!fin.eof())
		{
			//�q�ɮ�Ū���r��
			fin >> tempString;
			//�ѪR��x�}�аO"M"�A�p�G���O�}�Y���ܡA�N��OŪ���@�ӯx�}�F�A�n��Ȧs���x�}�s�_��
			if (tempString == "M")
			{
				if (currentLoadMatrixID != 0)
				{
					
					//�w�g�`���n����[�J�̫ᵲ�G
					tempVector.setName("$m" + std::to_string(MatrixVariableIndex) + "[" + std::to_string(tempMatrixRowIndex) + "]");
					tempMatrixData.push_back(tempVector);

					//Row�ƥؼW�[
					tempMatrixRowIndex++;

					tempVector.clear();
					//�]�w���s
					tempMatrixColIndex = 0;

					//�w�q�Ȧs�x�}��Ƶ��c
					Matrix tempMatrix;
					//�s�J�x�}���
					tempMatrix.setData(tempMatrixData);
					//�w�q�x�}�ܼƦW�١A��MatrixVariableIndex�ܼƧ@�W�٪�����
					std::string matrixVariableTemp = "$m" + std::to_string(MatrixVariableIndex);
					//�s�J�x�}�ܼƦW��
					tempMatrix.setName(matrixVariableTemp);
					//�s�J�x�}
					Matrices.push_back(tempMatrix);

					Matrices[MatrixVariableIndex].setcolNum(tempMatrixColNum);
					Matrices[MatrixVariableIndex].setrowNum(tempMatrixRowNum);
					//���WMatrixVariableIndex�A�H�T�O�ܼƦW�٤�����
					MatrixVariableIndex++;
					//�M���x�}��ƼȦs
					tempMatrixData.clear();
					tempVector.clear();

					tempMatrixColIndex = 0;
					tempMatrixRowIndex = 0;
				}
				//���WcurrentLoadMatrixID�A�аO���eŪ���x�}ID
				currentLoadMatrixID++;
				//�q�ɮ�Ū���r��A���o�x�}����
				fin >> tempString;
				tempMatrixRowNum = (int)strtod(tempString.c_str(), NULL);

				fin >> tempString;
				tempMatrixColNum = (int)strtod(tempString.c_str(), NULL);

				tempMatrixColNum = tempMatrixColNum;

				tempMatrixRowNum = tempMatrixRowNum;
			}
			else
			{
				
				//�p�Gcolumn�j�����]�w�h�N����F
				if (tempMatrixColIndex >= tempMatrixColNum) {
					
					//�w�g�`���n����[�J�̫ᵲ�G
					tempVector.setName("$m" + std::to_string(MatrixVariableIndex) + "[" + std::to_string(tempMatrixRowIndex) + "]");
					tempMatrixData.push_back(tempVector);

					//Row�ƥؼW�[
					tempMatrixRowIndex++;
					int num = tempMatrixData.size();
					num = num;
					tempVector.clear();
					//�]�w���s
					tempMatrixColIndex = 0;
				}

				//Ū���x�}��ơA�ñNstring�ରdouble
				double value;
				value = (double)strtod(tempString.c_str(), NULL);
				//�N�x�}��Ʀs�J�Ȧs
				tempVector.push_back(value);
				//�s�W�@��column
				tempMatrixColIndex++;

			}

		}

		//Row�ƥؼW�[
		tempMatrixRowIndex++;
		//�w�g�`���n����[�J�̫ᵲ�G
		tempMatrixData.push_back(tempVector);
		tempVector.clear();
		//�]�w���s
		tempMatrixColIndex = 0;

		//Ū�J��J�ɮפ��̫�@�ӦV�q��T
		Matrix tempMatrix;
		tempMatrix.setData(tempMatrixData);
		std::string matrixVariableTemp = "$m" + std::to_string(MatrixVariableIndex);
		tempMatrix.setName(matrixVariableTemp);
		tempMatrix.setcolNum(tempMatrixColNum);
		tempMatrix.setrowNum(tempMatrixRowNum);
		Matrices.push_back(tempMatrix);

		MatrixVariableIndex++;
		//Ū�����\�^��false
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
	//�N��X�榡�s�J�Ȧs
	std::string outputTemp = "[";
	//�N��X��Ʀs�J�Ȧs
	for (unsigned int j = 0; j < getData().size(); j++)
	{
		std::string scalarString = std::to_string(getData()[j]);
		outputTemp += scalarString.substr(0, scalarString.size());
		if (j != getData().size() - 1)
			outputTemp += ",";
	}
	//�N��X�榡�s�J�Ȧs�A�åB����
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

		//�p��C�Ӧ�m��determine�A�[�`
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
			{
				//��¦��
				double base = Vs[i].getData()[j];
				//std::cout << "base["<<i<<"]["<<j<<"] = " << Vs[i].getData()[j] << std::endl;
				//std::cout << "matrix[" << i << "][" << j << "] = "<<std::endl;
				//�إߤp�@�����x�}
				for (int ii = 0; ii < n; ii++) {
					//�Prow����
					if (ii != i) {
						for (int jj = 0; jj < n; jj++) {
							//�Pcolumn����
							if (jj != j) {
								//std::cout << Vs[ii].getData()[jj] << " ";
								newV.push_back(Vs[ii].getData()[jj]);
							}

						}
						//std::cout <<std::endl;
						//�@row�s���Bpush�i�h
						newVs.push_back(newV);
						newV.clear();
					}
				}

				//���o�U�@��determine
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

	//�����W�T��
	//��C�@�Ӱ�
	for (int i = 0; i < n; i++) {
		//�n���H���Y�ƪ����
		double base = Vs[i].getData()[i];

		//�V��U����row���t�Ƭ۴�A�ϱo�̫e�����Y�Ƭ�0
		for (int j = i + 1; j < n; j++) {
			//row�n���H������
			double scale = Vs[j].getData()[i] / base;
			//���H���Ƥ���۴�
			Vs[j] = Vector::add(Vs[j],Vector::scale(Vs[i], -1 * scale));
		}
	}

	//�����N�i�H�αר��ۭ��A�o��determine
	for (int i = 0; i < n; i++) {
		result *= Vs[i].getData()[i];
	}

	return result;
}

std::vector<Vector> Vector::basis(std::vector<Vector> Vs, int n) {
	std::vector<Vector> result;

	//�����A�Ĥ@�ӦV�q���κ�
	//���L���⥿�W��
	result.push_back(Vector::normalization(Vs[0]));

	//���U�ӨC�ӦV�q����e���V�q���B�z
	for (int i = 1; i < n; i++) {
		for (int j = i - 1; j >= 0; j--) {
			//�e�����V�q
			Vector tempV = Vs[j];
			//�W�@�ӦV�q���Wdot���H����
			//�]�����@�U�n���۴�A�ҥH���W-1
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
	//�N��X��Ʀs�J�Ȧs
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
	//�N��X�榡�s�J�Ȧs�A�åB����
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

	//��̫ᵲ�G�n���C��@����
	//���C��row
	for (int i = 0; i < M1.getrowNum(); i++) {
		//���C��Col
		for (int j = 0; j < M2.getcolNum(); j++) {
			double value = 0;

			//�C��col���ۭ�
			for (int col = 0; col < M1.getcolNum(); col++) {
				value += M1.getData()[i].getData()[col] * M2.getData()[col].getData()[j];
			}

			tempV.push_back(value);
		}
		//�@��row�����Npush
		result.push_back(tempV);
		tempV.clear();
	}

	return result;
}

Matrix Matrix::row_echelon(Matrix M) {
	int colNum = M.getcolNum();
	int rowNum = M.getrowNum();
	//�ѤW����U
	for (int i = 0; i < rowNum; i++) {
		//�n���H���Y�ƪ����
		double base = M.getData()[i].getData()[i];
		std::cout << "base = " << base << std::endl;
		//�p�Gbase�O0�A�N����̤U���A�ˬd�O�_�i�H��
		//���զ��ơA�p�G�쩳���S���D�s���Ƥ]�n���U
		int testTime = 1;
		while (base == 0 && testTime + i < rowNum)
		{
			base = M.getData()[testTime + i].getData()[i];
			std::cout << " base = " << base << std::endl;
			testTime++;
		}

		if (testTime > 1) {
			M.swapRow(i, testTime - 1 + i);
			//�p�G���洫�A�n��-1
			M.getData()[i] = Vector::scale(M.getData()[i], -1);
		}

		if (base != 0) {
			//�V��U����row���t�Ƭ۴�A�ϱo�̫e�����Y�Ƭ�0
			for (int j = i + 1; j < rowNum; j++) {
				//row�n���H������
				double scale = M.getData()[j].getData()[i] / base;
				std::cout << "--scale["<<j<<"]["<<i<<"] = " << scale << std::endl;
				Vector scaled = Vector::scale(M.getData()[i], scale);

				//���H���Ƥ���۴�
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

	//�令�W�T���x�}
	M = Matrix::row_echelon(M);
	//�ˬd�O�_�@���row��0
	bool zeroRow = true;

	for (int i = rowNum - 1; i >= 0; i--) {
		for (int j = colNum - 1; j >= 0; j--) {
			//�u�n����@��row���O�s�A�N���ΦA���F
			if (M.getData()[i].getData()[j] != 0) {
				zeroRow = false;
				break;
			}
		}
		if (zeroRow) {
			result -= 1;
		}
		else {
			//�u�n����@��row���O�s�A�N���ΦA���F
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

	//�ѤW����U
	//�s���G
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
	//�����W�T��
	//��C�@�Ӱ�

	M = Matrix::row_echelon(M);

	//�����N�i�H�αר��ۭ��A�o��determine
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
	Matrix tempM;//������Matrix
	Vector tempV;

	//�p��C�Ӧ�m��determine
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			//���o����Mtrix
			for (int ii = 0; ii < n; ii++) {
				//�Prow����
				if (ii != i) {
					for (int jj = 0; jj < n; jj++) {
						//�Pcolumn����
						if (jj != j) {
							tempV.push_back(tempM.getData()[ii].getData()[jj]);
						}

					}
					//�@row�s���Bpush�i�h
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