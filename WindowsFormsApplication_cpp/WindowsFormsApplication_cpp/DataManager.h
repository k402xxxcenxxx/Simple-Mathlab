#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
//�w�q�V�q��Ƶ��c
struct Vector
{
	std::string Name;
	std::vector<double> Data;
};
//�w�q���޸��class
class DataManager
{
private:
	//�x�s�V�q���
	std::vector<Vector> Vectors;
	//�����V�qID�A�Ω󱱺�
	int  VectorVariableIndex;
	//�����ɮ׸��|�W��
	std::string FileName;
public:
	DataManager();
	//Ū���V�q���
	bool LoadVectorData();
	//���o�V�q���
	std::vector<Vector> GetVectors();
	//Ū���x�}���
	bool LoadMetrixData();
	//���o�x�}���
	std::vector<Vector> GetMetrixs();
	//�]�m�ɮ׸��|�W��
	void SetFileName(std::string fileName);
};
