#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<numeric>
//�w�q�V�q��Ƶ��c
class Vector
{
private:
	std::string Name;
	std::vector<double> Data;
public:
	std::string getName() { return Name; }
	std::vector<double> getData() { return Data; }

	void setName(std::string myName) { Name = myName; }
	void setData(std::vector<double> myData) { Data = myData; }

	void push_back(double value) { Data.push_back(value); }
	void clear() { Data.clear(); }

	std::string print();

	static double dot(Vector V1, Vector V2);
	static Vector add(Vector V1, Vector V2);
	static Vector scale(Vector V, double value);
	static double norm(Vector V);
	static Vector normalization(Vector V);
	static bool isOrthogonal(Vector V1, Vector V2);
	static Vector crossProduct(Vector V1, Vector V2);
	static double angle(Vector V1, Vector V2);
};

//�w�q�V�q��Ƶ��c
class Matrix
{
private:
	std::string Name;
	std::vector<Vector> Data;
	int colNum;
	int rowNum;
public:
	std::string getName() { return Name; }
	std::vector<Vector> getData() { return Data; }
	Vector getData(int rowNum) { return Data.at(rowNum); }
	int getcolNum() { return colNum; }
	int getrowNum() { return rowNum; }

	void setName(std::string myName) { Name = myName; }
	void setData(std::vector<Vector> myData) { Data = myData; }
	void setcolNum(int mycolNum) { colNum = mycolNum; }
	void setrowNum(int myrowNum) { rowNum = myrowNum; }

	std::string print();
};

//�w�q���޸��class
class DataManager
{
private:
	//�x�s�V�q���
	std::vector<Vector> Vectors;
	//�����V�qID�A�Ω󱱺�
	int  VectorVariableIndex;

	//�x�s�x�}���
	std::vector<Matrix> Matrices;
	//�����x�}ID�A�Ω󱱺�
	int  MatrixVariableIndex;

	//�����ɮ׸��|�W��
	std::string FileName;
public:
	DataManager();

	//Ū���V�q���
	bool LoadVectorData();
	//���o�V�q���
	std::vector<Vector> GetVectors();

	//Ū���x�}���
	bool LoadMatrixData();
	//���o�x�}���
	std::vector<Matrix> GetMatrices();
	//�]�m�ɮ׸��|�W��
	void SetFileName(std::string fileName);
};
