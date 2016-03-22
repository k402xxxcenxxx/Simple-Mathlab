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
					tempVector.Data = tempVectorData;
					//�w�q�V�q�ܼƦW�١A��VectorVariableIndex�ܼƧ@�W�٪�����
					std::string vectorVariableTemp = "$v" + std::to_string(VectorVariableIndex);
					//�s�J�V�q�ܼƦW��
					tempVector.Name = vectorVariableTemp;
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
		tempVector.Data = tempVectorData;
		std::string vectorVariableTemp = "$v" + std::to_string(VectorVariableIndex);
		tempVector.Name = vectorVariableTemp;
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
		std::vector<std::vector<double>> tempMatrixData;
		//�w�q�x�}��ƼȦsRow
		std::vector<double> tempValues;
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
		char* pEnd;
		//�q�ɮ�Ū���r��A���o�x�}�`��
		fin >> tempString;
		inputMatrixCount = (int)strtod(tempString.c_str(), NULL);

		//����Ū�ɰj��A�æbŪ���ɮ׵����ɵ����A�άOŪ����w�ƶq���x�}�ᵲ��
		while (!fin.eof() || currentLoadMatrixID == inputMatrixCount)
		{
			//�q�ɮ�Ū���r��
			fin >> tempString;
			//�ѪR��x�}�аO"M"�A�p�G���O�}�Y���ܡA�N��OŪ���@�ӯx�}�F�A�n��Ȧs���x�}�s�_��
			if (tempString == "M")
			{
				if (currentLoadMatrixID != 0)
				{
					//�w�q�Ȧs�x�}��Ƶ��c
					Matrix tempMatrix;
					//�s�J�x�}���
					tempMatrix.Data = tempMatrixData;
					//�w�q�x�}�ܼƦW�١A��MatrixVariableIndex�ܼƧ@�W�٪�����
					std::string matrixVariableTemp = "$m" + std::to_string(MatrixVariableIndex);
					//�s�J�x�}�ܼƦW��
					tempMatrix.Name = matrixVariableTemp;
					//�s�J�x�}
					Matrices.push_back(tempMatrix);
					//���WMatrixVariableIndex�A�H�T�O�ܼƦW�٤�����
					MatrixVariableIndex++;
					//�M���x�}��ƼȦs
					tempMatrixData.clear();
				}
				//���WcurrentLoadMatrixID�A�аO���eŪ���x�}ID
				currentLoadMatrixID++;
				//�q�ɮ�Ū���r��A���o�x�}����
				fin >> tempString;

				tempMatrixColNum = (int)strtod(tempString.c_str(), &pEnd);
				tempMatrixRowNum = (int)strtod(pEnd, NULL);
			}
			else
			{
				tempMatrixColIndex++;
				//����F
				if (tempMatrixColIndex >= tempMatrixColNum) {
					//Row�ƥؼW�[
					tempMatrixRowIndex++;
					//�w�g�`���n����[�J�̫ᵲ�G
					tempMatrixData.push_back(tempValues);
					tempValues.clear();
					//�]�w���s
					tempMatrixColIndex = 0;
				}

				//Ū���x�}��ơA�ñNstring�ରdouble
				double value;
				value = (double)strtod(tempString.c_str(), NULL);
				//�N�x�}��Ʀs�J�Ȧs
				tempValues.push_back(value);

			}

		}
		//Ū�J��J�ɮפ��̫�@�ӦV�q��T
		Matrix tempMatrix;
		tempMatrix.Data = tempMatrixData;
		std::string matrixVariableTemp = "$m" + std::to_string(MatrixVariableIndex);
		tempMatrix.Name = matrixVariableTemp;
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

