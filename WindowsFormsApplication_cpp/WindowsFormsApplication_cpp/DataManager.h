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
	static Vector add(Vector V1, Vector V2, bool testTinyValue = false);
	static Vector sub(Vector V1, Vector V2, bool testTinyValue = false);
	static Vector scale(Vector V, double value);
	static double norm(Vector V);
	static Vector normalization(Vector V);
	static bool isOrthogonal(Vector V1, Vector V2);
	static Vector crossProduct(Vector V1, Vector V2);
	static Vector planeNormal(Vector V1, Vector V2);
	static double angle(Vector V1, Vector V2);
	static double triangle_area(Vector V1, Vector V2);
	static double determine_slow(std::vector<Vector> Vs, int n);//�Ѥ�⪺�覡��o���A�|�W�C�A�򥻤W�]���X���G
	static double determine(std::vector<Vector> Vs,int n);
	static std::vector<Vector> basis(std::vector<Vector> Vs, int n);
	static double com(Vector V1, Vector V2);
	static Vector proj(Vector V1, Vector V2);
	static bool paralell(Vector V1, Vector V2);
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
	
	Matrix() {
		colNum = 0;
		rowNum = 0;
	}

	Matrix(int row,int col) {
		colNum = col;
		rowNum = row;
	}

	std::string getName() { return Name; }
	std::vector<Vector> getData() { return Data; }
	Vector getData(int rowNum) { return Data.at(rowNum); }
	int getcolNum() { return colNum; }
	int getrowNum() { return rowNum; }

	double get(int row, int column) {
		return Data[row].getData()[column];
	}

	void push_back(Vector value) { Data.push_back(value); }
	void clear() { Data.clear(); }
	void swapRow(int fromIndex, int toIndex) {
		Vector tempV = Data[toIndex];
		Data[toIndex] = Data[fromIndex];
		Data[fromIndex] = tempV;
	}
	void moveRowToBottom(int Index) {
		Vector tempV = Data.at(Index);
		Data.erase(Data.begin() + Index);
		Data.push_back(tempV);
	}

	void setDataAt(Vector myData,int index) { Data[index] = myData; }
	void setDataAt(double myData, int row,int column) { Data[row].getData()[column] = myData; }

	void setName(std::string myName) { Name = myName; }
	void setData(std::vector<Vector> myData) { Data = myData; }
	void setcolNum(int mycolNum) { colNum = mycolNum; }
	void setrowNum(int myrowNum) { rowNum = myrowNum; }

	bool isErrorMatrix() {
		if (rowNum == 0 && colNum == 0) {
			return true;
		}
		else
			return false;
	}

	std::string print();
	static Matrix add(Matrix M1, Matrix M2, bool testTinyValue = false);
	static Matrix sub(Matrix M1, Matrix M2, bool testTinyValue = false);
	static Matrix multi(Matrix M1, Matrix M2);
	static Matrix row_echelon(Matrix M);
	static int rank(Matrix M);
	static Matrix transpose(Matrix M);
	static double determine(Matrix M, int n);
	static Matrix inverse_matrix(Matrix M,int n);
	static Matrix adjoint(Matrix M, int n);
	static Matrix LS_method(Matrix M1,Matrix M2);

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
