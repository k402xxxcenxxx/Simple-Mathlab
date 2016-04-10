#pragma once
#include"DataManager.h"
#include"DotNetUtilities.h"

namespace WindowsFormsApplication_cpp {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// WindowsForm 的摘要
	/// </summary>
	public ref class WindowsForm : public System::Windows::Forms::Form
	{
	public:
		WindowsForm(void)
		{
			InitializeComponent();
			dataManager = new DataManager();
			lastInputLength = -1;
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~WindowsForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^  menuStrip2;
	private: System::Windows::Forms::ToolStripMenuItem^  FileToolStripMenuItem;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::ToolStripMenuItem^  LoadVectorToolStripMenuItem;









	private: System::Windows::Forms::TextBox^  Input;

	private: System::Windows::Forms::ListBox^  VectorList;



	protected:















	protected:

	private:
		/// <summary>
			DataManager* dataManager;
			String^ userInput;
			int lastInputLength;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^  loadMatrixToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog2;

	private: System::Windows::Forms::ListBox^  MatrixList;
	private: System::Windows::Forms::TextBox^  Output;
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	private: System::Windows::Forms::SplitContainer^  splitContainer2;
	private: System::Windows::Forms::SplitContainer^  splitContainer3;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::GroupBox^  groupBox3;
	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::ListBox^  listBox1;







			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->FileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LoadVectorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadMatrixToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->Output = (gcnew System::Windows::Forms::TextBox());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->MatrixList = (gcnew System::Windows::Forms::ListBox());
			this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->Input = (gcnew System::Windows::Forms::TextBox());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->VectorList = (gcnew System::Windows::Forms::ListBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip2->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->groupBox4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->BeginInit();
			this->splitContainer3->Panel1->SuspendLayout();
			this->splitContainer3->Panel2->SuspendLayout();
			this->splitContainer3->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip2
			// 
			this->menuStrip2->ImageScalingSize = System::Drawing::Size(32, 32);
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->FileToolStripMenuItem });
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Padding = System::Windows::Forms::Padding(13, 4, 0, 4);
			this->menuStrip2->Size = System::Drawing::Size(502, 27);
			this->menuStrip2->TabIndex = 1;
			this->menuStrip2->Text = L"menuStrip2";
			// 
			// FileToolStripMenuItem
			// 
			this->FileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->LoadVectorToolStripMenuItem,
					this->loadMatrixToolStripMenuItem
			});
			this->FileToolStripMenuItem->Name = L"FileToolStripMenuItem";
			this->FileToolStripMenuItem->Size = System::Drawing::Size(38, 19);
			this->FileToolStripMenuItem->Text = L"File";
			// 
			// LoadVectorToolStripMenuItem
			// 
			this->LoadVectorToolStripMenuItem->Name = L"LoadVectorToolStripMenuItem";
			this->LoadVectorToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->LoadVectorToolStripMenuItem->Text = L"Load Vector";
			this->LoadVectorToolStripMenuItem->Click += gcnew System::EventHandler(this, &WindowsForm::LoadVectorToolStripMenuItem_Click);
			// 
			// loadMatrixToolStripMenuItem
			// 
			this->loadMatrixToolStripMenuItem->Name = L"loadMatrixToolStripMenuItem";
			this->loadMatrixToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->loadMatrixToolStripMenuItem->Text = L"Load Matrix";
			this->loadMatrixToolStripMenuItem->Click += gcnew System::EventHandler(this, &WindowsForm::loadMatrixToolStripMenuItem_Click);
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				84.43198F)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				15.56802F)));
			this->tableLayoutPanel1->Controls->Add(this->splitContainer1, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->groupBox1, 1, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 27);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 1342)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(502, 343);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(3, 3);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->splitContainer2);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->splitContainer3);
			this->splitContainer1->Size = System::Drawing::Size(417, 337);
			this->splitContainer1->SplitterDistance = 209;
			this->splitContainer1->SplitterWidth = 9;
			this->splitContainer1->TabIndex = 1;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer2->Location = System::Drawing::Point(0, 0);
			this->splitContainer2->Name = L"splitContainer2";
			this->splitContainer2->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->groupBox2);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->groupBox4);
			this->splitContainer2->Size = System::Drawing::Size(209, 337);
			this->splitContainer2->SplitterDistance = 166;
			this->splitContainer2->SplitterWidth = 8;
			this->splitContainer2->TabIndex = 6;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->Output);
			this->groupBox2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic))));
			this->groupBox2->Location = System::Drawing::Point(0, 0);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Padding = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->groupBox2->Size = System::Drawing::Size(209, 166);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Output";
			// 
			// Output
			// 
			this->Output->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Output->Font = (gcnew System::Drawing::Font(L"新細明體", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Output->Location = System::Drawing::Point(7, 22);
			this->Output->Multiline = true;
			this->Output->Name = L"Output";
			this->Output->ReadOnly = true;
			this->Output->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->Output->Size = System::Drawing::Size(195, 138);
			this->Output->TabIndex = 1;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->MatrixList);
			this->groupBox4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox4->Location = System::Drawing::Point(0, 0);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Padding = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->groupBox4->Size = System::Drawing::Size(209, 163);
			this->groupBox4->TabIndex = 6;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"MatrixList";
			// 
			// MatrixList
			// 
			this->MatrixList->Dock = System::Windows::Forms::DockStyle::Fill;
			this->MatrixList->FormattingEnabled = true;
			this->MatrixList->HorizontalScrollbar = true;
			this->MatrixList->ItemHeight = 12;
			this->MatrixList->Location = System::Drawing::Point(7, 21);
			this->MatrixList->Name = L"MatrixList";
			this->MatrixList->Size = System::Drawing::Size(195, 136);
			this->MatrixList->TabIndex = 5;
			this->MatrixList->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &WindowsForm::MatrixList_MouseDoubleClick);
			// 
			// splitContainer3
			// 
			this->splitContainer3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer3->Location = System::Drawing::Point(0, 0);
			this->splitContainer3->Name = L"splitContainer3";
			this->splitContainer3->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer3.Panel1
			// 
			this->splitContainer3->Panel1->Controls->Add(this->groupBox3);
			// 
			// splitContainer3.Panel2
			// 
			this->splitContainer3->Panel2->Controls->Add(this->groupBox5);
			this->splitContainer3->Size = System::Drawing::Size(199, 337);
			this->splitContainer3->SplitterDistance = 166;
			this->splitContainer3->SplitterWidth = 8;
			this->splitContainer3->TabIndex = 1;
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->Input);
			this->groupBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox3->Location = System::Drawing::Point(0, 0);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Padding = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->groupBox3->Size = System::Drawing::Size(199, 166);
			this->groupBox3->TabIndex = 2;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Input";
			// 
			// Input
			// 
			this->Input->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Input->Location = System::Drawing::Point(7, 21);
			this->Input->Multiline = true;
			this->Input->Name = L"Input";
			this->Input->Size = System::Drawing::Size(185, 139);
			this->Input->TabIndex = 1;
			this->Input->TextChanged += gcnew System::EventHandler(this, &WindowsForm::Input_TextChanged);
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->VectorList);
			this->groupBox5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox5->Location = System::Drawing::Point(0, 0);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Padding = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->groupBox5->Size = System::Drawing::Size(199, 163);
			this->groupBox5->TabIndex = 4;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"VectorList";
			// 
			// VectorList
			// 
			this->VectorList->Dock = System::Windows::Forms::DockStyle::Fill;
			this->VectorList->FormattingEnabled = true;
			this->VectorList->HorizontalScrollbar = true;
			this->VectorList->ItemHeight = 12;
			this->VectorList->Location = System::Drawing::Point(7, 21);
			this->VectorList->Name = L"VectorList";
			this->VectorList->Size = System::Drawing::Size(185, 136);
			this->VectorList->TabIndex = 3;
			this->VectorList->SelectedIndexChanged += gcnew System::EventHandler(this, &WindowsForm::VectorList_SelectedIndexChanged);
			this->VectorList->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &WindowsForm::VectorList_MouseDoubleClick);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->listBox1);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Location = System::Drawing::Point(426, 3);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(7, 6, 7, 6);
			this->groupBox1->Size = System::Drawing::Size(73, 337);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"method";
			// 
			// listBox1
			// 
			this->listBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 12;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(22) {
				L"print", L"dot", L"add", L"sub", L"scale", L"multi",
					L"norm", L"normalize", L"isOrthogonal", L"angle", L"cross", L"planeNormal", L"determine", L"basis", L"rank", L"transpose", L"paralell",
					L"projection", L"component", L"adjoint", L"inverse", L"leastSquare"
			});
			this->listBox1->Location = System::Drawing::Point(7, 21);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(59, 310);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &WindowsForm::listBox1_SelectedIndexChanged);
			this->listBox1->DoubleClick += gcnew System::EventHandler(this, &WindowsForm::listBox1_DoubleClick);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->InitialDirectory = L"../";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &WindowsForm::openFileDialog1_FileOk);
			// 
			// openFileDialog2
			// 
			this->openFileDialog2->FileName = L"openFileDialog2";
			this->openFileDialog2->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &WindowsForm::openFileDialog2_FileOk);
			// 
			// WindowsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(502, 370);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->menuStrip2);
			this->Name = L"WindowsForm";
			this->Text = L"VectorExample";
			this->Load += gcnew System::EventHandler(this, &WindowsForm::WindowsForm_Load);
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->splitContainer3->Panel1->ResumeLayout(false);
			this->splitContainer3->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->EndInit();
			this->splitContainer3->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void WindowsForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void LoadVectorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	//開啟Dialog
	openFileDialog1->ShowDialog();
}
private: System::Void Input_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	//當Input textbox中的輸入改變時，便會進入此函式
	//取得向量資料
	std::vector<Vector> vectors = dataManager->GetVectors();
	std::vector<Matrix> matrices = dataManager->GetMatrices();
	//判斷輸入自元為'\n'，並防止取到字串-1位置
	if (Input->Text->Length-1 >= 0 &&Input->Text[Input->Text->Length - 1] == '\n')
	{
		//將使用者輸入字串(在userInput中)，依空白作切割
		array<String^> ^userCommand = userInput->Split(' ');
		//字串比較，若指令為"print"的情況

		if (userCommand[0] == "print")
		{
			//定意輸出暫存
			String^ outputTemp = "";
			bool exist = false;
			//透過for迴圈，從向量資料中找出對應變數
			for (unsigned int i = 0; i < vectors.size();i++)
			{
				//若變數名稱與指令變數名稱符合
				if (userCommand[1] == gcnew String(vectors[i].getName().c_str()))
				{
					
					outputTemp = gcnew String(vectors[i].print().c_str()) + Environment::NewLine;
					//輸出暫存資訊
					Output->Text += gcnew String(vectors[i].getName().c_str()) +" = "+ outputTemp;
					break;
					
				}
			}
			
			//透過for迴圈，從矩陣資料中找出對應變數
			for (unsigned int i = 0; i < matrices.size(); i++)
			{
				if (exist == true) {
					break;
				}
				//若變數名稱與指令變數名稱符合
				if (userCommand[1] == gcnew String(matrices[i].getName().c_str()))
				{
					outputTemp = gcnew String( matrices[i].print().c_str());
					//輸出暫存資訊
					Output->Text += gcnew String(matrices[i].getName().c_str()) + " = " + outputTemp + Environment::NewLine;
					break;
				}
			}
		}
		else if (userCommand[0] == "dot") {
			//是否只輸入兩個參數
			if (userCommand->Length == 3) {

				bool existInVector = false;
				bool finished = false;
				Vector Vfirst;
				Vector Vsecond;
				//確認第一個是否是向量
				//透過for迴圈，從向量資料中找出對應變數
				for (unsigned int i = 0; i < vectors.size(); i++)
				{

					//若變數名稱與指令變數名稱符合
					if (userCommand[1] == gcnew String(vectors[i].getName().c_str()))
					{
						Vfirst = vectors[i];
						existInVector = true;
						break;
					}
				}

				//如果第一個是向量，才再找第二個
				if (existInVector) {
					for (unsigned int i = 0; i < vectors.size(); i++)
					{
						//若變數名稱與指令變數名稱符合
						if (userCommand[2] == gcnew String(vectors[i].getName().c_str()))
						{
							Vsecond = vectors[i];
							finished = true;
							break;
						}
					}
				}
				else if (!existInVector) {
					//透過for迴圈，從矩陣資料中找出對應變數
					for (unsigned int i = 0; i < matrices.size(); i++)
					{

						//若變數名稱與指令變數名稱符合
						if (userCommand[1] == gcnew String(matrices[i].getName().c_str()))
						{

							break;
						}
					}
				}

				if (finished && existInVector) {
					if (Vfirst.getData().size() == Vsecond.getData().size()) {
						Output->Text += gcnew String(Vfirst.getName().c_str()) + " dot " + gcnew String(Vsecond.getName().c_str()) + " = " + Vector::dot(Vfirst, Vsecond).ToString() + Environment::NewLine;
					}
					else {
						Output->Text += gcnew String(Vfirst.getName().c_str()) + " & " + gcnew String(Vsecond.getName().c_str()) + "can't do dot" + Environment::NewLine;
					}
				}
				else {
					Output->Text += "-Coming soon-" + Environment::NewLine;
				}
			}
			else {
				if (userCommand->Length > 3) {
					Output->Text += "-Too much input for dot function-" + Environment::NewLine;
				}else if (userCommand->Length < 3) {
					Output->Text += "-Too few input for dot function-" + Environment::NewLine;
				}
			}
		}
		else if (userCommand[0] == "add") {
			//是否只輸入兩個參數
			if (userCommand->Length == 3) {

				bool existInVector = false;
				bool existInMatrix = false;
				bool finished = false;
				Vector Vfirst;
				Vector Vsecond;
				Matrix Mfirst;
				Matrix Msecond;
				//確認第一個是否是向量
				//透過for迴圈，從向量資料中找出對應變數
				for (unsigned int i = 0; i < vectors.size(); i++)
				{

					//若變數名稱與指令變數名稱符合
					if (userCommand[1] == gcnew String(vectors[i].getName().c_str()))
					{
						Vfirst = vectors[i];
						existInVector = true;
						break;
					}
				}

				//如果第一個是向量，才再找第二個
				if (existInVector) {
					for (unsigned int i = 0; i < vectors.size(); i++)
					{
						//若變數名稱與指令變數名稱符合
						if (userCommand[2] == gcnew String(vectors[i].getName().c_str()))
						{
							Vsecond = vectors[i];
							finished = true;
							break;
						}
					}
				}
				else if (!existInVector) {
					//透過for迴圈，從矩陣資料中找出對應變數
					for (unsigned int i = 0; i < matrices.size(); i++)
					{

						//若變數名稱與指令變數名稱符合
						if (userCommand[1] == gcnew String(matrices[i].getName().c_str()))
						{
							Mfirst = matrices[i];
							existInMatrix = true;
							break;
						}
					}

					if (existInMatrix) {
						//透過for迴圈，從矩陣資料中找出對應變數
						for (unsigned int i = 0; i < matrices.size(); i++)
						{
							//若變數名稱與指令變數名稱符合
							if (userCommand[2] == gcnew String(matrices[i].getName().c_str()))
							{
								Msecond = matrices[i];
								finished = true;
								break;
							}
						}
					}
				}

				if (finished && existInVector) {
					if (Vfirst.getData().size() == Vsecond.getData().size()) {
						Output->Text += gcnew String(Vfirst.getName().c_str()) + " add " + gcnew String(Vsecond.getName().c_str()) + " = " + gcnew String(Vector::add(Vfirst, Vsecond).print().c_str()) + Environment::NewLine;
					}
					else {
						Output->Text += gcnew String(Vfirst.getName().c_str()) + " & " + gcnew String(Vsecond.getName().c_str()) + "can't do add" + Environment::NewLine;
					}
				}else if (finished && existInMatrix) {
					if (Mfirst.getcolNum() == Msecond.getcolNum() && Mfirst.getrowNum() == Msecond.getrowNum()) {
						Output->Text += gcnew String(Mfirst.getName().c_str()) + " add " + gcnew String(Msecond.getName().c_str()) + " = " + gcnew String(Matrix::add(Mfirst, Msecond).print().c_str()) + Environment::NewLine;
					}
					else {
						Output->Text += gcnew String(Mfirst.getName().c_str()) + " & " + gcnew String(Msecond.getName().c_str()) + "can't do add" + Environment::NewLine;
					}
				}
				else {
					Output->Text += "-Coming soon-" + Environment::NewLine;
				}
			}
			else {
				if (userCommand->Length > 3) {
					Output->Text += "-Too much input for add function-" + Environment::NewLine;
				}
				else if (userCommand->Length < 3) {
					Output->Text += "-Too few input for add function-" + Environment::NewLine;
				}
			}
		}
		else if (userCommand[0] == "sub") {
			//是否只輸入兩個參數
			if (userCommand->Length == 3) {

				bool existInVector = false;
				bool existInMatrix = false;
				bool finished = false;
				Vector Vfirst;
				Vector Vsecond;
				Matrix Mfirst;
				Matrix Msecond;
				//確認第一個是否是向量
				//透過for迴圈，從向量資料中找出對應變數
				for (unsigned int i = 0; i < vectors.size(); i++)
				{

					//若變數名稱與指令變數名稱符合
					if (userCommand[1] == gcnew String(vectors[i].getName().c_str()))
					{
						Vfirst = vectors[i];
						existInVector = true;
						break;
					}
				}

				//如果第一個是向量，才再找第二個
				if (existInVector) {
					for (unsigned int i = 0; i < vectors.size(); i++)
					{
						//若變數名稱與指令變數名稱符合
						if (userCommand[2] == gcnew String(vectors[i].getName().c_str()))
						{
							Vsecond = vectors[i];
							finished = true;
							break;
						}
					}
				}
				else if (!existInVector) {
					//透過for迴圈，從矩陣資料中找出對應變數
					for (unsigned int i = 0; i < matrices.size(); i++)
					{

						//若變數名稱與指令變數名稱符合
						if (userCommand[1] == gcnew String(matrices[i].getName().c_str()))
						{
							Mfirst = matrices[i];
							existInMatrix = true;
							break;
						}
					}

					if (existInMatrix) {
						//透過for迴圈，從矩陣資料中找出對應變數
						for (unsigned int i = 0; i < matrices.size(); i++)
						{
							//若變數名稱與指令變數名稱符合
							if (userCommand[2] == gcnew String(matrices[i].getName().c_str()))
							{
								Msecond = matrices[i];
								finished = true;
								break;
							}
						}
					}
				}

				if (finished && existInVector) {
					if (Vfirst.getData().size() == Vsecond.getData().size()) {
						Output->Text += gcnew String(Vfirst.getName().c_str()) + " sub " + gcnew String(Vsecond.getName().c_str()) + " = " + gcnew String(Vector::sub(Vfirst, Vsecond).print().c_str()) + Environment::NewLine;
					}
					else {
						Output->Text += gcnew String(Vfirst.getName().c_str()) + " & " + gcnew String(Vsecond.getName().c_str()) + "can't do sub" + Environment::NewLine;
					}
				}
				else if (finished && existInMatrix) {
					if (Mfirst.getcolNum() == Msecond.getcolNum() && Mfirst.getrowNum() == Msecond.getrowNum()) {
						Output->Text += gcnew String(Mfirst.getName().c_str()) + " sub " + gcnew String(Msecond.getName().c_str()) + " = " + gcnew String(Matrix::sub(Mfirst, Msecond).print().c_str()) + Environment::NewLine;
					}
					else {
						Output->Text += gcnew String(Mfirst.getName().c_str()) + " & " + gcnew String(Msecond.getName().c_str()) + "can't do sub" + Environment::NewLine;
					}
				}
				else {
					Output->Text += "-Coming soon-" + Environment::NewLine;
				}
			}
			else {
				if (userCommand->Length > 3) {
					Output->Text += "-Too much input for add function-" + Environment::NewLine;
				}
				else if (userCommand->Length < 3) {
					Output->Text += "-Too few input for add function-" + Environment::NewLine;
				}
			}
		}
		else if (userCommand[0] == "scale") {
			//是否只輸入兩個參數
			if (userCommand->Length == 3) {

				bool existInVector = false;
				bool finished = false;
				Vector Vfirst;
				double value;
				//確認第一個是否是向量
				//透過for迴圈，從向量資料中找出對應變數
				for (unsigned int i = 0; i < vectors.size(); i++)
				{

					//若變數名稱與指令變數名稱符合
					if (userCommand[1] == gcnew String(vectors[i].getName().c_str()))
					{
						Vfirst = vectors[i];
						existInVector = true;
						break;
					}
				}
				if (existInVector) {
					//若變數名稱與指令變數名稱符合
					if (double::TryParse(userCommand[2],value))
					{
						finished = true;
					}
				}
				else if (!existInVector) {
					//透過for迴圈，從矩陣資料中找出對應變數
					for (unsigned int i = 0; i < matrices.size(); i++)
					{

						//若變數名稱與指令變數名稱符合
						if (userCommand[1] == gcnew String(matrices[i].getName().c_str()))
						{

							break;
						}
					}
				}

				if (finished && existInVector) {
					Output->Text += gcnew String(Vfirst.getName().c_str()) + " scale " + value + " = " + gcnew String(Vector::scale(Vfirst, value).print().c_str()) + Environment::NewLine;
				}
				else {
					Output->Text += "-Coming soon-" + Environment::NewLine;
				}
			}
			else {
				if (userCommand->Length > 3) {
					Output->Text += "-Too much input for scale function-" + Environment::NewLine;
				}
				else if (userCommand->Length < 3) {
					Output->Text += "-Too few input for scale function-" + Environment::NewLine;
				}
			}
		}
		else if (userCommand[0] == "multi") {
			//是否只輸入兩個參數
			if (userCommand->Length == 3) {

				bool existInMatrix = false;
				bool finished = false;
				Matrix Mfirst;
				Matrix Msecond;
				
				//透過for迴圈，從矩陣資料中找出對應變數
				for (unsigned int i = 0; i < matrices.size(); i++)
				{

					//若變數名稱與指令變數名稱符合
					if (userCommand[1] == gcnew String(matrices[i].getName().c_str()))
					{
						Mfirst = matrices[i];
						existInMatrix = true;
						break;
					}
				}

				if (existInMatrix) {
					//透過for迴圈，從矩陣資料中找出對應變數
					for (unsigned int i = 0; i < matrices.size(); i++)
					{
						//若變數名稱與指令變數名稱符合
						if (userCommand[2] == gcnew String(matrices[i].getName().c_str()))
						{
							Msecond = matrices[i];
							finished = true;
							break;
						}
					}
				}

				if (finished && existInMatrix) {
					if (Mfirst.getcolNum() == Msecond.getrowNum()) {
						Output->Text += gcnew String(Mfirst.getName().c_str()) + " multi " + gcnew String(Msecond.getName().c_str()) + " = " + gcnew String(Matrix::multi(Mfirst, Msecond).print().c_str()) + Environment::NewLine;
					}
					else {
						Output->Text += gcnew String(Mfirst.getName().c_str()) + " & " + gcnew String(Msecond.getName().c_str()) + "can't do multi" + Environment::NewLine;
					}
				}
				else {
					Output->Text += "-Coming soon-" + Environment::NewLine;
				}
			}
			else {
				if (userCommand->Length > 3) {
					Output->Text += "-Too much input for add function-" + Environment::NewLine;
				}
				else if (userCommand->Length < 3) {
					Output->Text += "-Too few input for add function-" + Environment::NewLine;
				}
			}
		}
		else if (userCommand[0] == "norm") {
			//是否只輸入一個參數
			if (userCommand->Length == 2) {

				bool finished = false;
				Vector Vfirst;
				//確認第一個是否是向量
				//透過for迴圈，從向量資料中找出對應變數
				for (unsigned int i = 0; i < vectors.size(); i++)
				{

					//若變數名稱與指令變數名稱符合
					if (userCommand[1] == gcnew String(vectors[i].getName().c_str()))
					{
						Vfirst = vectors[i];
						finished = true;
						break;
					}
				}

				if (finished) {
					Output->Text += gcnew String(Vfirst.getName().c_str()) + " norm = " + Vector::norm(Vfirst) + Environment::NewLine;
				}
				else {
					Output->Text += "-No such vector-" + Environment::NewLine;
				}
			}
			else {
				if (userCommand->Length > 2) {
					Output->Text += "-Too much input for norm function-" + Environment::NewLine;
				}
				else if (userCommand->Length < 2) {
					Output->Text += "-Too few input for norm function-" + Environment::NewLine;
				}
			}
		}
		else if (userCommand[0] == "normalize") {
			//是否只輸入一個參數
			if (userCommand->Length == 2) {

				bool finished = false;
				Vector Vfirst;
				//確認第一個是否是向量
				//透過for迴圈，從向量資料中找出對應變數
				for (unsigned int i = 0; i < vectors.size(); i++)
				{

					//若變數名稱與指令變數名稱符合
					if (userCommand[1] == gcnew String(vectors[i].getName().c_str()))
					{
						Vfirst = vectors[i];
						finished = true;
						break;
					}
				}

				if (finished) {
					Output->Text += gcnew String(Vfirst.getName().c_str()) + " normalize = " + gcnew String(Vector::normalization(Vfirst).print().c_str()) + Environment::NewLine;
				}
				else {
					Output->Text += "-No such vector-" + Environment::NewLine;
				}
			}
			else {
				if (userCommand->Length > 2) {
					Output->Text += "-Too much input for normalize function-" + Environment::NewLine;
				}
				else if (userCommand->Length < 2) {
					Output->Text += "-Too few input for normalize function-" + Environment::NewLine;
				}
			}
		}
		else if (userCommand[0] == "isOrthogonal") {
			//是否只輸入兩個參數
			if (userCommand->Length == 3) {

				bool existInVector = false;
				bool finished = false;
				Vector Vfirst;
				Vector Vsecond;
				//確認第一個是否是向量
				//透過for迴圈，從向量資料中找出對應變數
				for (unsigned int i = 0; i < vectors.size(); i++)
				{

					//若變數名稱與指令變數名稱符合
					if (userCommand[1] == gcnew String(vectors[i].getName().c_str()))
					{
						Vfirst = vectors[i];
						existInVector = true;
						break;
					}
				}

				//如果第一個是向量，才再找第二個
				if (existInVector) {
					for (unsigned int i = 0; i < vectors.size(); i++)
					{
						//若變數名稱與指令變數名稱符合
						if (userCommand[2] == gcnew String(vectors[i].getName().c_str()))
						{
							Vsecond = vectors[i];
							finished = true;
							break;
						}
					}
				}
				else if (!existInVector) {
					//透過for迴圈，從矩陣資料中找出對應變數
					for (unsigned int i = 0; i < matrices.size(); i++)
					{

						//若變數名稱與指令變數名稱符合
						if (userCommand[1] == gcnew String(matrices[i].getName().c_str()))
						{

							break;
						}
					}
				}

				if (finished && existInVector) {
					if (Vfirst.getData().size() == Vsecond.getData().size()) {
						if (Vector::isOrthogonal(Vfirst, Vsecond)) {
							Output->Text += "true" + Environment::NewLine;
						}else{
							Output->Text += "false" + Environment::NewLine;
						}
					}
					else {
						Output->Text += gcnew String(Vfirst.getName().c_str()) + " & " + gcnew String(Vsecond.getName().c_str()) + "can't judge orthogonal" + Environment::NewLine;
					}
				}
				else {
					Output->Text += "-Coming soon-" + Environment::NewLine;
				}
			}
			else {
				if (userCommand->Length > 3) {
					Output->Text += "-Too much input for add function-" + Environment::NewLine;
				}
				else if (userCommand->Length < 3) {
					Output->Text += "-Too few input for add function-" + Environment::NewLine;
				}
			}
		}
		else if (userCommand[0] == "angle") {
			//是否只輸入兩個參數
			if (userCommand->Length == 3) {

				bool existInVector = false;
				bool finished = false;
				Vector Vfirst;
				Vector Vsecond;
				//確認第一個是否是向量
				//透過for迴圈，從向量資料中找出對應變數
				for (unsigned int i = 0; i < vectors.size(); i++)
				{

					//若變數名稱與指令變數名稱符合
					if (userCommand[1] == gcnew String(vectors[i].getName().c_str()))
					{
						Vfirst = vectors[i];
						existInVector = true;
						break;
					}
				}

				//如果第一個是向量，才再找第二個
				if (existInVector) {
					for (unsigned int i = 0; i < vectors.size(); i++)
					{
						//若變數名稱與指令變數名稱符合
						if (userCommand[2] == gcnew String(vectors[i].getName().c_str()))
						{
							Vsecond = vectors[i];
							finished = true;
							break;
						}
					}
				}
				else if (!existInVector) {
					//透過for迴圈，從矩陣資料中找出對應變數
					for (unsigned int i = 0; i < matrices.size(); i++)
					{

						//若變數名稱與指令變數名稱符合
						if (userCommand[1] == gcnew String(matrices[i].getName().c_str()))
						{

							break;
						}
					}
				}

				if (finished && existInVector) {
					if (Vfirst.getData().size() == Vsecond.getData().size()) {
						Output->Text += "Angle between" + gcnew String(Vfirst.getName().c_str()) + " & " + gcnew String(Vsecond.getName().c_str()) + " = " + Vector::angle(Vfirst,Vsecond) + Environment::NewLine;
					}
					else {
						Output->Text += gcnew String(Vfirst.getName().c_str()) + " & " + gcnew String(Vsecond.getName().c_str()) + "can't get angle" + Environment::NewLine;
					}
				}
				else {
					Output->Text += "-Coming soon-" + Environment::NewLine;
				}
			}
			else {
				if (userCommand->Length > 3) {
					Output->Text += "-Too much input for add function-" + Environment::NewLine;
				}
				else if (userCommand->Length < 3) {
					Output->Text += "-Too few input for add function-" + Environment::NewLine;
				}
			}
		}
		else if (userCommand[0] == "cross") {
			//是否只輸入兩個參數
			if (userCommand->Length == 3) {

				bool existInVector = false;
				bool finished = false;
				Vector Vfirst;
				Vector Vsecond;
				//確認第一個是否是向量
				//透過for迴圈，從向量資料中找出對應變數
				for (unsigned int i = 0; i < vectors.size(); i++)
				{

					//若變數名稱與指令變數名稱符合
					if (userCommand[1] == gcnew String(vectors[i].getName().c_str()))
					{
						Vfirst = vectors[i];
						existInVector = true;
						break;
					}
				}

				//如果第一個是向量，才再找第二個
				if (existInVector) {
					for (unsigned int i = 0; i < vectors.size(); i++)
					{
						//若變數名稱與指令變數名稱符合
						if (userCommand[2] == gcnew String(vectors[i].getName().c_str()))
						{
							Vsecond = vectors[i];
							finished = true;
							break;
						}
					}
				}
				else if (!existInVector) {
					//透過for迴圈，從矩陣資料中找出對應變數
					for (unsigned int i = 0; i < matrices.size(); i++)
					{

						//若變數名稱與指令變數名稱符合
						if (userCommand[1] == gcnew String(matrices[i].getName().c_str()))
						{

							break;
						}
					}
				}

				if (finished && existInVector) {
					if (Vfirst.getData().size() == Vsecond.getData().size() && Vfirst.getData().size() == 3) {
						Output->Text += gcnew String(Vfirst.getName().c_str()) + " cross " + gcnew String(Vsecond.getName().c_str()) + " = " + gcnew String(Vector::crossProduct(Vfirst, Vsecond).print().c_str()) + Environment::NewLine;
					}
					else {
						Output->Text += gcnew String(Vfirst.getName().c_str()) + " & " + gcnew String(Vsecond.getName().c_str()) + "can't do cross" + Environment::NewLine;
					}
				}
				else {
					Output->Text += "-Coming soon-" + Environment::NewLine;
				}
			}
			else {
				if (userCommand->Length > 3) {
					Output->Text += "-Too much input for add function-" + Environment::NewLine;
				}
				else if (userCommand->Length < 3) {
					Output->Text += "-Too few input for add function-" + Environment::NewLine;
				}
			}
		}
		else if (userCommand[0] == "planeNormal") {
			//是否只輸入兩個參數
			if (userCommand->Length == 3) {

				bool existInVector = false;
				bool finished = false;
				Vector Vfirst;
				Vector Vsecond;
				//確認第一個是否是向量
				//透過for迴圈，從向量資料中找出對應變數
				for (unsigned int i = 0; i < vectors.size(); i++)
				{

					//若變數名稱與指令變數名稱符合
					if (userCommand[1] == gcnew String(vectors[i].getName().c_str()))
					{
						Vfirst = vectors[i];
						existInVector = true;
						break;
					}
				}

				//如果第一個是向量，才再找第二個
				if (existInVector) {
					for (unsigned int i = 0; i < vectors.size(); i++)
					{
						//若變數名稱與指令變數名稱符合
						if (userCommand[2] == gcnew String(vectors[i].getName().c_str()))
						{
							Vsecond = vectors[i];
							finished = true;
							break;
						}
					}
				}
				else if (!existInVector) {
					//透過for迴圈，從矩陣資料中找出對應變數
					for (unsigned int i = 0; i < matrices.size(); i++)
					{

						//若變數名稱與指令變數名稱符合
						if (userCommand[1] == gcnew String(matrices[i].getName().c_str()))
						{

							break;
						}
					}
				}

				if (finished && existInVector) {
					if (Vfirst.getData().size() == Vsecond.getData().size() && Vfirst.getData().size() == 3) {
						Output->Text += "the plane normal that is produced by "+ gcnew String(Vfirst.getName().c_str()) + " & " + gcnew String(Vsecond.getName().c_str()) + " = " + gcnew String(Vector::planeNormal(Vfirst, Vsecond).print().c_str()) + Environment::NewLine;
					}
					else {
						Output->Text += gcnew String(Vfirst.getName().c_str()) + " & " + gcnew String(Vsecond.getName().c_str()) + "can't do cross" + Environment::NewLine;
					}
				}
				else {
					Output->Text += "-Coming soon-" + Environment::NewLine;
				}
			}
			else {
				if (userCommand->Length > 3) {
					Output->Text += "-Too much input for add function-" + Environment::NewLine;
				}
				else if (userCommand->Length < 3) {
					Output->Text += "-Too few input for add function-" + Environment::NewLine;
				}
			}
		}
		else if (userCommand[0] == "determine") {
			//是否輸入超過兩個參數
			//如果是做向量的determine，輸入的數量至少三個
			if (userCommand->Length >= 3) {
				//n = ?
				int dimension = 0;
				//是否為向量
				bool existInVector = false;
				bool finished = false;
				std::vector<Vector> Vlist;
				//確認第一個是否是向量
				//透過for迴圈，從向量資料中找出對應變數
				for (unsigned int i = 0; i < vectors.size(); i++)
				{

					//若變數名稱與指令變數名稱符合
					if (userCommand[1] == gcnew String(vectors[i].getName().c_str()))
					{
						Vlist.push_back(vectors[i]);
						existInVector = true;
						dimension = vectors[i].getData().size();
						break;
					}
				}

				//如果第一個是向量，才往之後的找
				if (existInVector) {
					//因為只有n*n矩陣，所以只找n次
					for (int i = 1; i < dimension; i++) {
						//是否有在list中找到
						bool exist = false;
						for (unsigned int j = 0; j < vectors.size() && !exist; j++)
						{
							
							//若變數名稱與接下來的指令變數名稱符合
							if (userCommand[i + 1] == gcnew String(vectors[j].getName().c_str()))
							{
								//size跟維度相同才能繼續做
								if (vectors[j].getData().size() == dimension) {
									exist = true;
									Vlist.push_back(vectors[j]);
									break;
								}
								else {
									Output->Text += "-input set of vectors can't do dimension-" + Environment::NewLine;
									return;
								}
							}
						}

						//如果其中某個vector找不到也不用做了
						if(!exist){
							Output->Text += "-input set of vectors contain invalid vector-" + Environment::NewLine;
							return;
						}
					}

					//完成所有的存入
					finished = true;
					
				}
				

				if (finished && existInVector) {
					std::cout << "determine vector" << std::endl;
						Output->Text += "determine = " + Vector::determine(Vlist,dimension).ToString() + Environment::NewLine;
					
				}
				else {
					Output->Text += "-Coming soon-" + Environment::NewLine;
				}
			}
			//如果是做矩陣的determine，則只會有兩個
			else if(userCommand->Length == 2){
				bool existInMatrices = false;
				Matrix targetMatrix;

				//透過for迴圈，從矩陣資料中找出對應變數
				for (unsigned int i = 0; i < matrices.size(); i++)
				{
					//若變數名稱與指令變數名稱符合
					if (userCommand[1] == gcnew String(matrices[i].getName().c_str()))
					{
						existInMatrices = true;
						targetMatrix = matrices[i];
						break;
					}
				}

				if (existInMatrices) {
					//還必須是n*n矩陣
					if (targetMatrix.getcolNum() == targetMatrix.getrowNum()) {
						Output->Text += "The determine of " + gcnew String(targetMatrix.getName().c_str()) + " = " + Matrix::determine(targetMatrix,targetMatrix.getcolNum()) + Environment::NewLine;
					}
					else {
						Output->Text += "-Input matrix not a n*n matrix-" + Environment::NewLine;
					}
				}

			}else if (userCommand->Length < 2) {
				Output->Text += "-Too few input for determine function-" + Environment::NewLine;
			}
		}
		else if (userCommand[0] == "basis") {
			//是否輸入超過兩個參數
			//如果是做向量的determine，輸入的數量至少三個
			if (userCommand->Length >= 3) {
				//n = ?
				int dimension = 0;
				//是否為向量
				bool existInVector = false;
				bool finished = false;
				std::vector<Vector> Vlist;
				//確認第一個是否是向量
				//透過for迴圈，從向量資料中找出對應變數
				for (unsigned int i = 0; i < vectors.size(); i++)
				{

					//若變數名稱與指令變數名稱符合
					if (userCommand[1] == gcnew String(vectors[i].getName().c_str()))
					{
						Vlist.push_back(vectors[i]);
						existInVector = true;
						dimension = vectors[i].getData().size();
						break;
					}
				}

				//如果第一個是向量，才往之後的找
				if (existInVector) {
					//因為只有n*n矩陣，所以只找n次
					for (int i = 1; i < dimension; i++) {
						//是否有在list中找到
						bool exist = false;
						for (unsigned int j = 0; j < vectors.size() && !exist; j++)
						{

							//若變數名稱與接下來的指令變數名稱符合
							if (userCommand[i + 1] == gcnew String(vectors[j].getName().c_str()))
							{
								//size跟維度相同才能繼續做
								if (vectors[j].getData().size() == dimension) {
									exist = true;
									Vlist.push_back(vectors[j]);
									break;
								}
								else {
									Output->Text += "-input set of vectors can't do dimension-" + Environment::NewLine;
									return;
								}
							}
						}

						//如果其中某個vector找不到也不用做了
						if (!exist) {
							Output->Text += "-input set of vectors contain invalid vector-" + Environment::NewLine;
							return;
						}
					}

					//完成所有的存入
					finished = true;

				}


				if (finished && existInVector) {
					Vlist = Vector::basis(Vlist, dimension);
					std::cout << "basis vector" << std::endl;
					Output->Text += "basis vector = " + Environment::NewLine;
					for (int i = 0; i < Vlist.size(); i++) {
						String^ outputTemp = gcnew String(Vlist[i].print().c_str()) + Environment::NewLine;
						Output->Text += outputTemp;
					}

				}
				else {
					Output->Text += "-Coming soon-" + Environment::NewLine;
				}
			}
			else{
				Output->Text += "-Too few input for determine function-" + Environment::NewLine;
			}
		}
		else if (userCommand[0] == "rank") {
			//是否只輸入超過一個參數
			if (userCommand->Length == 2) {
				bool existInMatrices = false;
				Matrix targetMatrix;

				//透過for迴圈，從矩陣資料中找出對應變數
				for (unsigned int i = 0; i < matrices.size(); i++)
				{
					//若變數名稱與指令變數名稱符合
					if (userCommand[1] == gcnew String(matrices[i].getName().c_str()))
					{
						existInMatrices = true;
						targetMatrix = matrices[i];
						break;
					}
				}

				if (existInMatrices) {
					
					Output->Text += "The rank of " + gcnew String(targetMatrix.getName().c_str()) + " = " + Matrix::rank(targetMatrix) + Environment::NewLine;
					
				}
				else {
					Output->Text += "-Can't find matrix-" + Environment::NewLine;

				}

			}
			else if (userCommand->Length < 2) {
				Output->Text += "-Too few input for determine function-" + Environment::NewLine;
			}
			else if (userCommand->Length > 2) {
				Output->Text += "-Too much input for determine function-" + Environment::NewLine;
			}
		}
		else if (userCommand[0] == "transpose") {
			//是否只輸入一個參數
			if (userCommand->Length == 2) {

				bool finished = false;
				Matrix Mfirst;

				//透過for迴圈，從矩陣資料中找出對應變數
				for (unsigned int i = 0; i < matrices.size(); i++)
				{

					//若變數名稱與指令變數名稱符合
					if (userCommand[1] == gcnew String(matrices[i].getName().c_str()))
					{
						Mfirst = matrices[i];
						finished = true;
						break;
					}
				}

				if (finished) {
					
					Output->Text += gcnew String(Mfirst.getName().c_str()) + " transpose = " + gcnew String(Matrix::transpose(Mfirst).print().c_str()) + Environment::NewLine;
					
				}
				else {
					Output->Text += "-Can't find matrix-" + Environment::NewLine;
				}
			}
			else {
				if (userCommand->Length > 3) {
					Output->Text += "-Too much input for add function-" + Environment::NewLine;
				}
				else if (userCommand->Length < 3) {
					Output->Text += "-Too few input for add function-" + Environment::NewLine;
				}
			}
		}
		else if (userCommand[0] == "adjoint") {
			//是否只輸入超過一個參數
			if (userCommand->Length == 2) {
				bool existInMatrices = false;
				Matrix targetMatrix;

				//透過for迴圈，從矩陣資料中找出對應變數
				for (unsigned int i = 0; i < matrices.size(); i++)
				{
					//若變數名稱與指令變數名稱符合
					if (userCommand[1] == gcnew String(matrices[i].getName().c_str()))
					{
						existInMatrices = true;
						targetMatrix = matrices[i];
						break;
					}
				}

				if (existInMatrices) {
					if(targetMatrix.getcolNum() == targetMatrix.getrowNum())
						Output->Text += "The adjoint matrix is " + gcnew String(targetMatrix.getName().c_str()) + " = " + gcnew String(Matrix::adjoint(targetMatrix,targetMatrix.getcolNum()).print().c_str()) + Environment::NewLine;
					else
						Output->Text += "-Not a n*n matrix-" + Environment::NewLine;
				}
				else {
					Output->Text += "-Can't find matrix-" + Environment::NewLine;

				}

			}
			else if (userCommand->Length < 2) {
				Output->Text += "-Too few input for adjoint function-" + Environment::NewLine;
			}
			else if (userCommand->Length > 2) {
				Output->Text += "-Too much input for adjoint function-" + Environment::NewLine;
			}
		}
		else if (userCommand[0] == "inverse") {
			//是否只輸入超過一個參數
			if (userCommand->Length == 2) {
				bool existInMatrices = false;
				Matrix targetMatrix;

				//透過for迴圈，從矩陣資料中找出對應變數
				for (unsigned int i = 0; i < matrices.size(); i++)
				{
					//若變數名稱與指令變數名稱符合
					if (userCommand[1] == gcnew String(matrices[i].getName().c_str()))
					{
						existInMatrices = true;
						targetMatrix = matrices[i];
						break;
					}
				}

				if (existInMatrices) {
					if (targetMatrix.getcolNum() == targetMatrix.getrowNum()) {
							Output->Text += "The inverse matrix is " + gcnew String(targetMatrix.getName().c_str()) + " = " + gcnew String(Matrix::inverse_matrix(targetMatrix, targetMatrix.getcolNum()).print().c_str()) + Environment::NewLine;
						
						
					}
					else
						Output->Text += "-Not a n*n matrix-" + Environment::NewLine;
				}
				else {
					Output->Text += "-Can't find matrix-" + Environment::NewLine;

				}

			}
			else if (userCommand->Length < 2) {
				Output->Text += "-Too few input for inverse function-" + Environment::NewLine;
			}
			else if (userCommand->Length > 2) {
				Output->Text += "-Too much input for inverse function-" + Environment::NewLine;
			}
		}
		else if (userCommand[0] == "leastSquare") {
			//是否只輸入兩個參數
			if (userCommand->Length == 3) {

				bool existInMatrix = false;
				bool finished = false;
				Matrix Mfirst;
				Matrix Msecond;

				//透過for迴圈，從矩陣資料中找出對應變數
				for (unsigned int i = 0; i < matrices.size(); i++)
				{

					//若變數名稱與指令變數名稱符合
					if (userCommand[1] == gcnew String(matrices[i].getName().c_str()))
					{
						Mfirst = matrices[i];
						existInMatrix = true;
						break;
					}
				}

				if (existInMatrix) {
					//透過for迴圈，從矩陣資料中找出對應變數
					for (unsigned int i = 0; i < matrices.size(); i++)
					{
						//若變數名稱與指令變數名稱符合
						if (userCommand[2] == gcnew String(matrices[i].getName().c_str()))
						{
							Msecond = matrices[i];
							finished = true;
							break;
						}
					}
				}

				if (finished && existInMatrix) {
					if (Mfirst.getrowNum() == Msecond.getrowNum()) {

						Output->Text += "least square of" + gcnew String(Mfirst.getName().c_str()) + " & " + gcnew String(Msecond.getName().c_str()) + " = " + gcnew String(Matrix::LS_method(Mfirst, Msecond).print().c_str()) + Environment::NewLine;
					}
					else {
						Output->Text += gcnew String(Mfirst.getName().c_str()) + " & " + gcnew String(Msecond.getName().c_str()) + "can't do multi" + Environment::NewLine;
					}
				}
				else {
					Output->Text += "-Coming soon-" + Environment::NewLine;
				}
			}
			else {
				if (userCommand->Length > 3) {
					Output->Text += "-Too much input for add function-" + Environment::NewLine;
				}
				else if (userCommand->Length < 3) {
					Output->Text += "-Too few input for add function-" + Environment::NewLine;
				}
			}
		}
		//反之則判斷找不到指令
		else
		{
			Output->Text += "-Command not found-" + Environment::NewLine;
		}
		userInput = "";
	}
	else
	{
		//將使用者輸入字串(在Text box中)，依'\n'作切割
		array<String^> ^userCommand = Input->Text->Split('\n');
		//並將最後一行，作為目前使用者輸入指令
		userInput = userCommand[userCommand->Length-1];
	}

}
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
{
	//在Dialog按下OK便會進入此函式
	//字串轉制string^ to string
	std::string tempFileName;
	MarshalString(openFileDialog1->FileName, tempFileName);
	//將檔案路徑名稱傳入dataManager
	dataManager->SetFileName(tempFileName);
	//從讀取讀取向量資料
	if (dataManager->LoadVectorData())
	{
		//將VectorList中項目先做清除
		VectorList->Items->Clear();	
		//取得所有向量資料
		std::vector<Vector> vectors = dataManager->GetVectors();

		for (unsigned int i = 0; i < vectors.size(); i++)
		{
			//將檔案名稱存入暫存
			std::string tempString = vectors[i].getName();
			//將輸出格式存入暫存
			tempString += " [";
			//將輸出資料存入暫存
			for (unsigned int j = 0; j<vectors[i].getData().size(); j++)
			{
				std::string scalarString = std::to_string(vectors[i].getData()[j]);
				tempString += scalarString.substr(0, scalarString.size() - 5);
				if (j != vectors[i].getData().size() - 1)
					tempString += ",";
			}
			//將輸出格式存入暫存
			tempString += "]";
			//將項目加入VectorList中
			VectorList->Items->Add(gcnew String(tempString.c_str()));
		}
		Output->Text += "-Vector datas have been loaded-" + Environment::NewLine;
	}
}
private: System::Void VectorList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void loadMatrixToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//開啟Dialog
	openFileDialog2->ShowDialog();
}
private: System::Void openFileDialog2_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	//在Dialog按下OK便會進入此函式
	//字串轉制string^ to string
	std::string tempFileName;
	MarshalString(openFileDialog2->FileName, tempFileName);
	//將檔案路徑名稱傳入dataManager
	dataManager->SetFileName(tempFileName);
	//從讀取讀取向量資料
	if (dataManager->LoadMatrixData())
	{
		//將VectorList中項目先做清除
		MatrixList->Items->Clear();
		//取得所有向量資料
		std::vector<Matrix> matrices = dataManager->GetMatrices();

		for (int i = 0; i < matrices.size(); i++)
		{
			//將檔案名稱存入暫存
			std::string tempString = matrices[i].getName();
			//將輸出格式存入暫存
			tempString += " [";
			//將輸出資料存入暫存
			for (int j = 0; j < matrices[i].getrowNum(); j++)
			{
				tempString += " [";
				for (int k = 0; k < matrices[i].getcolNum(); k++)
				{
					std::string scalarString = std::to_string((matrices[i].getData().at(j)).getData().at(k));
					tempString += scalarString.substr(0, scalarString.size() - 5);
					if (k != matrices[i].getcolNum() - 1)
						tempString += ",";
				}
				tempString += "]";
				
				if (j != matrices[i].getrowNum() - 1)
					tempString += ",";
			}
			//將輸出格式存入暫存
			tempString += "]";
			//將項目加入VectorList中
			MatrixList->Items->Add(gcnew String(tempString.c_str()));
		}
		Output->Text += "-Matrix datas have been loaded-" + Environment::NewLine;
	}
}

private: System::Void listBox1_DoubleClick(System::Object^  sender, System::EventArgs^  e) {
	Input->Text += listBox1->SelectedItem->ToString() + " ";
}
private: System::Void VectorList_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//取得向量資料
	std::vector<Vector> vectors = dataManager->GetVectors();
	Input->Text += gcnew String(vectors[VectorList->SelectedIndex].getName().c_str()) + " ";
}
private: System::Void MatrixList_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//取得向量資料
	std::vector<Matrix> matrices = dataManager->GetMatrices();
	Input->Text += gcnew String(matrices[MatrixList->SelectedIndex].getName().c_str()) + " ";
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
