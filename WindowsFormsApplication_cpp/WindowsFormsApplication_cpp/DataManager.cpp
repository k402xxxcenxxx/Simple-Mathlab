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
		while (!fin.eof())
		{
			//�q�ɮ�Ū���r��
			fin >> tempString;
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
		Vector tempValues;
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
					//Row�ƥؼW�[
					tempMatrixRowIndex++;
					//�w�g�`���n����[�J�̫ᵲ�G
					tempMatrixData.push_back(tempValues);
					tempValues.getData().clear();
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
					tempValues.getData().clear();

					tempMatrixColIndex = 0;
					tempMatrixRowIndex = 0;
				}
				//���WcurrentLoadMatrixID�A�аO���eŪ���x�}ID
				currentLoadMatrixID++;
				//�q�ɮ�Ū���r��A���o�x�}����
				fin >> tempString;
				tempMatrixColNum = (int)strtod(tempString.c_str(), NULL);

				fin >> tempString;
				tempMatrixRowNum = (int)strtod(tempString.c_str(), NULL);
			}
			else
			{
				
				//�p�Gcolumn�j�����]�w�h�N����F
				if (tempMatrixColIndex >= tempMatrixColNum) {
					//Row�ƥؼW�[
					tempMatrixRowIndex++;
					//�w�g�`���n����[�J�̫ᵲ�G
					tempMatrixData.push_back(tempValues);
					tempValues.getData().clear();
					//�]�w���s
					tempMatrixColIndex = 0;
				}

				//Ū���x�}��ơA�ñNstring�ରdouble
				double value;
				value = (double)strtod(tempString.c_str(), NULL);
				//�N�x�}��Ʀs�J�Ȧs
				tempValues.getData().push_back(value);
				//�s�W�@��column
				tempMatrixColIndex++;

			}

		}

		//Row�ƥؼW�[
		tempMatrixRowIndex++;
		//�w�g�`���n����[�J�̫ᵲ�G
		tempMatrixData.push_back(tempValues);
		tempValues.getData().clear();
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

		int num = tempMatrix.getrowNum();

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
		outputTemp += scalarString.substr(0, scalarString.size() - 5);
		if (j != getData().size() - 1)
			outputTemp += ",";
	}
	//�N��X�榡�s�J�Ȧs�A�åB����
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
	//�N��X��Ʀs�J�Ȧs
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
	//�N��X�榡�s�J�Ȧs�A�åB����
	outputTemp += "]\n";

	return outputTemp;
}


