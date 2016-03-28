#pragma once
#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<numeric>
//定義向量資料結構
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
	static double determine_slow(std::vector<Vector> Vs, int n);//由手算的方式算得的，會超慢，基本上跑不出結果
	static double determine(std::vector<Vector> Vs,int n);
	static std::vector<Vector> basis(std::vector<Vector> Vs, int n);
};

//定義向量資料結構
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

	void setName(std::string myName) { Name = myName; }
	void setData(std::vector<Vector> myData) { Data = myData; }
	void setcolNum(int mycolNum) { colNum = mycolNum; }
	void setrowNum(int myrowNum) { rowNum = myrowNum; }

	std::string print();
	static Matrix add(Matrix M1, Matrix M2, bool testTinyValue = false);
	static Matrix sub(Matrix M1, Matrix M2, bool testTinyValue = false);
	static Matrix multi(Matrix M1, Matrix M2);
	static Matrix row_echelon(Matrix M);
	static int rank(Matrix M);
	static double determine(Matrix M, int n);
};

//定義控管資料class
class DataManager
{
private:
	//儲存向量資料
	std::vector<Vector> Vectors;
	//紀錄向量ID，用於控管
	int  VectorVariableIndex;

	//儲存矩陣資料
	std::vector<Matrix> Matrices;
	//紀錄矩陣ID，用於控管
	int  MatrixVariableIndex;

	//紀錄檔案路徑名稱
	std::string FileName;
public:
	DataManager();

	//讀取向量資料
	bool LoadVectorData();
	//取得向量資料
	std::vector<Vector> GetVectors();

	//讀取矩陣資料
	bool LoadMatrixData();
	//取得矩陣資料
	std::vector<Matrix> GetMatrices();
	//設置檔案路徑名稱
	void SetFileName(std::string fileName);
};
