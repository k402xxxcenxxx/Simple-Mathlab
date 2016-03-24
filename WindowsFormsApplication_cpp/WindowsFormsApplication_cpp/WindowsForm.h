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
	/// WindowsForm ���K�n
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
		/// �M������ϥΤ����귽�C
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



	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel1;
	private: System::Windows::Forms::FlowLayoutPanel^  flowLayoutPanel2;
	private: System::Windows::Forms::Label^  OutputLabel;


	private: System::Windows::Forms::Label^  InputLabel;
	private: System::Windows::Forms::TextBox^  Input;
	private: System::Windows::Forms::Label^  VectorLabel;
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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ListBox^  MatrixList;
	private: System::Windows::Forms::TextBox^  Output;






			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����]�p�u��䴩�һݪ���k - �ФŨϥε{���X�s�边�ק�
		/// �o�Ӥ�k�����e�C
		/// </summary>
		void InitializeComponent(void)
		{
			this->menuStrip2 = (gcnew System::Windows::Forms::MenuStrip());
			this->FileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->LoadVectorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->loadMatrixToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->InputLabel = (gcnew System::Windows::Forms::Label());
			this->Input = (gcnew System::Windows::Forms::TextBox());
			this->VectorLabel = (gcnew System::Windows::Forms::Label());
			this->VectorList = (gcnew System::Windows::Forms::ListBox());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->OutputLabel = (gcnew System::Windows::Forms::Label());
			this->Output = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->MatrixList = (gcnew System::Windows::Forms::ListBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip2->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel1->SuspendLayout();
			this->flowLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip2
			// 
			this->menuStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->FileToolStripMenuItem });
			this->menuStrip2->Location = System::Drawing::Point(0, 0);
			this->menuStrip2->Name = L"menuStrip2";
			this->menuStrip2->Size = System::Drawing::Size(713, 24);
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
			this->FileToolStripMenuItem->Size = System::Drawing::Size(38, 20);
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
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel1, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->flowLayoutPanel2, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 24);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 651)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(713, 671);
			this->tableLayoutPanel1->TabIndex = 2;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Controls->Add(this->InputLabel);
			this->flowLayoutPanel1->Controls->Add(this->Input);
			this->flowLayoutPanel1->Controls->Add(this->VectorLabel);
			this->flowLayoutPanel1->Controls->Add(this->VectorList);
			this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel1->Location = System::Drawing::Point(359, 3);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(351, 665);
			this->flowLayoutPanel1->TabIndex = 0;
			// 
			// InputLabel
			// 
			this->InputLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->InputLabel->AutoSize = true;
			this->InputLabel->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->InputLabel->Location = System::Drawing::Point(3, 0);
			this->InputLabel->Name = L"InputLabel";
			this->InputLabel->Size = System::Drawing::Size(41, 16);
			this->InputLabel->TabIndex = 0;
			this->InputLabel->Text = L"Input";
			// 
			// Input
			// 
			this->Input->Dock = System::Windows::Forms::DockStyle::Top;
			this->Input->Location = System::Drawing::Point(3, 19);
			this->Input->Multiline = true;
			this->Input->Name = L"Input";
			this->Input->Size = System::Drawing::Size(348, 272);
			this->Input->TabIndex = 1;
			this->Input->TextChanged += gcnew System::EventHandler(this, &WindowsForm::Input_TextChanged);
			// 
			// VectorLabel
			// 
			this->VectorLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->VectorLabel->AutoSize = true;
			this->VectorLabel->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->VectorLabel->Location = System::Drawing::Point(3, 294);
			this->VectorLabel->Name = L"VectorLabel";
			this->VectorLabel->Size = System::Drawing::Size(47, 16);
			this->VectorLabel->TabIndex = 2;
			this->VectorLabel->Text = L"Vector";
			// 
			// VectorList
			// 
			this->VectorList->FormattingEnabled = true;
			this->VectorList->HorizontalScrollbar = true;
			this->VectorList->ItemHeight = 12;
			this->VectorList->Location = System::Drawing::Point(3, 313);
			this->VectorList->Name = L"VectorList";
			this->VectorList->Size = System::Drawing::Size(348, 352);
			this->VectorList->TabIndex = 3;
			this->VectorList->SelectedIndexChanged += gcnew System::EventHandler(this, &WindowsForm::VectorList_SelectedIndexChanged);
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->Controls->Add(this->OutputLabel);
			this->flowLayoutPanel2->Controls->Add(this->Output);
			this->flowLayoutPanel2->Controls->Add(this->label1);
			this->flowLayoutPanel2->Controls->Add(this->MatrixList);
			this->flowLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->flowLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(350, 665);
			this->flowLayoutPanel2->TabIndex = 1;
			// 
			// OutputLabel
			// 
			this->OutputLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->OutputLabel->AutoSize = true;
			this->OutputLabel->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->OutputLabel->Location = System::Drawing::Point(3, 0);
			this->OutputLabel->Name = L"OutputLabel";
			this->OutputLabel->Size = System::Drawing::Size(52, 16);
			this->OutputLabel->TabIndex = 0;
			this->OutputLabel->Text = L"Output";
			// 
			// Output
			// 
			this->Output->Dock = System::Windows::Forms::DockStyle::Top;
			this->Output->Font = (gcnew System::Drawing::Font(L"PMingLiU", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Output->Location = System::Drawing::Point(3, 19);
			this->Output->Multiline = true;
			this->Output->Name = L"Output";
			this->Output->ReadOnly = true;
			this->Output->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->Output->Size = System::Drawing::Size(347, 272);
			this->Output->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei", 9, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(3, 294);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 16);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Matrix";
			// 
			// MatrixList
			// 
			this->MatrixList->FormattingEnabled = true;
			this->MatrixList->HorizontalScrollbar = true;
			this->MatrixList->ItemHeight = 12;
			this->MatrixList->Location = System::Drawing::Point(3, 313);
			this->MatrixList->Name = L"MatrixList";
			this->MatrixList->Size = System::Drawing::Size(347, 352);
			this->MatrixList->TabIndex = 5;
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
			this->ClientSize = System::Drawing::Size(713, 695);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Controls->Add(this->menuStrip2);
			this->Name = L"WindowsForm";
			this->Text = L"VectorExample";
			this->Load += gcnew System::EventHandler(this, &WindowsForm::WindowsForm_Load);
			this->menuStrip2->ResumeLayout(false);
			this->menuStrip2->PerformLayout();
			this->tableLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->ResumeLayout(false);
			this->flowLayoutPanel1->PerformLayout();
			this->flowLayoutPanel2->ResumeLayout(false);
			this->flowLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void WindowsForm_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void LoadVectorToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	//�}��Dialog
	openFileDialog1->ShowDialog();
}
private: System::Void Input_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	//��Input textbox������J���ܮɡA�K�|�i�J���禡
	//���o�V�q���
	std::vector<Vector> vectors = dataManager->GetVectors();
	std::vector<Matrix> matrices = dataManager->GetMatrices();
	//�P�_��J�ۤ���'\n'�A�è������r��-1��m
	if (Input->Text->Length-1 >= 0 &&Input->Text[Input->Text->Length - 1] == '\n')
	{
		//�N�ϥΪ̿�J�r��(�buserInput��)�A�̪ťէ@����
		array<String^> ^userCommand = userInput->Split(' ');
		//�r�����A�Y���O��"print"�����p

		if (userCommand[0] == "print")
		{
			//�w�N��X�Ȧs
			String^ outputTemp = "";
			bool exist = false;
			//�z�Lfor�j��A�q�V�q��Ƥ���X�����ܼ�
			for (unsigned int i = 0; i < vectors.size();i++)
			{
				//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
				if (userCommand[1] == gcnew String(vectors[i].getName().c_str()))
				{
					
					outputTemp = gcnew String(vectors[i].print().c_str()) + Environment::NewLine;
					//��X�Ȧs��T
					Output->Text += gcnew String(vectors[i].getName().c_str()) +" = "+ outputTemp;
					break;
					
				}
			}
			
			//�z�Lfor�j��A�q�x�}��Ƥ���X�����ܼ�
			for (unsigned int i = 0; i < matrices.size(); i++)
			{
				if (exist == true) {
					break;
				}
				//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
				if (userCommand[1] == gcnew String(matrices[i].getName().c_str()))
				{
					outputTemp = gcnew String( matrices[i].print().c_str());
					//��X�Ȧs��T
					Output->Text += gcnew String(matrices[i].getName().c_str()) + " = " + outputTemp + Environment::NewLine;
					break;
				}
			}
		}
		else if (userCommand[0] == "dot") {
			//�O�_�u��J��ӰѼ�
			if (userCommand->Length == 3) {

				bool existInVector = false;
				bool finished = false;
				Vector Vfirst;
				Vector Vsecond;
				//�T�{�Ĥ@�ӬO�_�O�V�q
				//�z�Lfor�j��A�q�V�q��Ƥ���X�����ܼ�
				for (unsigned int i = 0; i < vectors.size(); i++)
				{

					//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
					if (userCommand[1] == gcnew String(vectors[i].getName().c_str()))
					{
						Vfirst = vectors[i];
						existInVector = true;
						break;
					}
				}

				//�p�G�Ĥ@�ӬO�V�q�A�~�A��ĤG��
				if (existInVector) {
					for (unsigned int i = 0; i < vectors.size(); i++)
					{
						//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
						if (userCommand[2] == gcnew String(vectors[i].getName().c_str()))
						{
							Vsecond = vectors[i];
							finished = true;
							break;
						}
					}
				}
				else if (!existInVector) {
					//�z�Lfor�j��A�q�x�}��Ƥ���X�����ܼ�
					for (unsigned int i = 0; i < matrices.size(); i++)
					{

						//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
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
					Output->Text += "-Too less input for dot function-" + Environment::NewLine;
				}
			}
		}
		else if (userCommand[0] == "add") {
			//�O�_�u��J��ӰѼ�
			if (userCommand->Length == 3) {

				bool existInVector = false;
				bool finished = false;
				Vector Vfirst;
				Vector Vsecond;
				//�T�{�Ĥ@�ӬO�_�O�V�q
				//�z�Lfor�j��A�q�V�q��Ƥ���X�����ܼ�
				for (unsigned int i = 0; i < vectors.size(); i++)
				{

					//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
					if (userCommand[1] == gcnew String(vectors[i].getName().c_str()))
					{
						Vfirst = vectors[i];
						existInVector = true;
						break;
					}
				}

				//�p�G�Ĥ@�ӬO�V�q�A�~�A��ĤG��
				if (existInVector) {
					for (unsigned int i = 0; i < vectors.size(); i++)
					{
						//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
						if (userCommand[2] == gcnew String(vectors[i].getName().c_str()))
						{
							Vsecond = vectors[i];
							finished = true;
							break;
						}
					}
				}
				else if (!existInVector) {
					//�z�Lfor�j��A�q�x�}��Ƥ���X�����ܼ�
					for (unsigned int i = 0; i < matrices.size(); i++)
					{

						//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
						if (userCommand[1] == gcnew String(matrices[i].getName().c_str()))
						{

							break;
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
					Output->Text += "-Too less input for add function-" + Environment::NewLine;
				}
			}
		}
		else if (userCommand[0] == "scale") {
			//�O�_�u��J��ӰѼ�
			if (userCommand->Length == 3) {

				bool existInVector = false;
				bool finished = false;
				Vector Vfirst;
				double value;
				//�T�{�Ĥ@�ӬO�_�O�V�q
				//�z�Lfor�j��A�q�V�q��Ƥ���X�����ܼ�
				for (unsigned int i = 0; i < vectors.size(); i++)
				{

					//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
					if (userCommand[1] == gcnew String(vectors[i].getName().c_str()))
					{
						Vfirst = vectors[i];
						existInVector = true;
						break;
					}
				}
				if (existInVector) {
					//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
					if (double::TryParse(userCommand[2],value))
					{
						finished = true;
					}
				}
				else if (!existInVector) {
					//�z�Lfor�j��A�q�x�}��Ƥ���X�����ܼ�
					for (unsigned int i = 0; i < matrices.size(); i++)
					{

						//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
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
					Output->Text += "-Too less input for scale function-" + Environment::NewLine;
				}
			}
		}
		else if (userCommand[0] == "norm") {
			//�O�_�u��J�@�ӰѼ�
			if (userCommand->Length == 2) {

				bool finished = false;
				Vector Vfirst;
				//�T�{�Ĥ@�ӬO�_�O�V�q
				//�z�Lfor�j��A�q�V�q��Ƥ���X�����ܼ�
				for (unsigned int i = 0; i < vectors.size(); i++)
				{

					//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
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
					Output->Text += "-Too less input for norm function-" + Environment::NewLine;
				}
			}
		}
		else if (userCommand[0] == "normalize") {
			//�O�_�u��J�@�ӰѼ�
			if (userCommand->Length == 2) {

				bool finished = false;
				Vector Vfirst;
				//�T�{�Ĥ@�ӬO�_�O�V�q
				//�z�Lfor�j��A�q�V�q��Ƥ���X�����ܼ�
				for (unsigned int i = 0; i < vectors.size(); i++)
				{

					//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
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
					Output->Text += "-Too less input for normalize function-" + Environment::NewLine;
				}
			}
		}
		else if (userCommand[0] == "isOrthogonal") {
			//�O�_�u��J��ӰѼ�
			if (userCommand->Length == 3) {

				bool existInVector = false;
				bool finished = false;
				Vector Vfirst;
				Vector Vsecond;
				//�T�{�Ĥ@�ӬO�_�O�V�q
				//�z�Lfor�j��A�q�V�q��Ƥ���X�����ܼ�
				for (unsigned int i = 0; i < vectors.size(); i++)
				{

					//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
					if (userCommand[1] == gcnew String(vectors[i].getName().c_str()))
					{
						Vfirst = vectors[i];
						existInVector = true;
						break;
					}
				}

				//�p�G�Ĥ@�ӬO�V�q�A�~�A��ĤG��
				if (existInVector) {
					for (unsigned int i = 0; i < vectors.size(); i++)
					{
						//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
						if (userCommand[2] == gcnew String(vectors[i].getName().c_str()))
						{
							Vsecond = vectors[i];
							finished = true;
							break;
						}
					}
				}
				else if (!existInVector) {
					//�z�Lfor�j��A�q�x�}��Ƥ���X�����ܼ�
					for (unsigned int i = 0; i < matrices.size(); i++)
					{

						//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
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
					Output->Text += "-Too less input for add function-" + Environment::NewLine;
				}
			}
		}
		else if (userCommand[0] == "angle") {
			//�O�_�u��J��ӰѼ�
			if (userCommand->Length == 3) {

				bool existInVector = false;
				bool finished = false;
				Vector Vfirst;
				Vector Vsecond;
				//�T�{�Ĥ@�ӬO�_�O�V�q
				//�z�Lfor�j��A�q�V�q��Ƥ���X�����ܼ�
				for (unsigned int i = 0; i < vectors.size(); i++)
				{

					//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
					if (userCommand[1] == gcnew String(vectors[i].getName().c_str()))
					{
						Vfirst = vectors[i];
						existInVector = true;
						break;
					}
				}

				//�p�G�Ĥ@�ӬO�V�q�A�~�A��ĤG��
				if (existInVector) {
					for (unsigned int i = 0; i < vectors.size(); i++)
					{
						//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
						if (userCommand[2] == gcnew String(vectors[i].getName().c_str()))
						{
							Vsecond = vectors[i];
							finished = true;
							break;
						}
					}
				}
				else if (!existInVector) {
					//�z�Lfor�j��A�q�x�}��Ƥ���X�����ܼ�
					for (unsigned int i = 0; i < matrices.size(); i++)
					{

						//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
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
					Output->Text += "-Too less input for add function-" + Environment::NewLine;
				}
			}
		}
		else if (userCommand[0] == "cross") {
			//�O�_�u��J��ӰѼ�
			if (userCommand->Length == 3) {

				bool existInVector = false;
				bool finished = false;
				Vector Vfirst;
				Vector Vsecond;
				//�T�{�Ĥ@�ӬO�_�O�V�q
				//�z�Lfor�j��A�q�V�q��Ƥ���X�����ܼ�
				for (unsigned int i = 0; i < vectors.size(); i++)
				{

					//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
					if (userCommand[1] == gcnew String(vectors[i].getName().c_str()))
					{
						Vfirst = vectors[i];
						existInVector = true;
						break;
					}
				}

				//�p�G�Ĥ@�ӬO�V�q�A�~�A��ĤG��
				if (existInVector) {
					for (unsigned int i = 0; i < vectors.size(); i++)
					{
						//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
						if (userCommand[2] == gcnew String(vectors[i].getName().c_str()))
						{
							Vsecond = vectors[i];
							finished = true;
							break;
						}
					}
				}
				else if (!existInVector) {
					//�z�Lfor�j��A�q�x�}��Ƥ���X�����ܼ�
					for (unsigned int i = 0; i < matrices.size(); i++)
					{

						//�Y�ܼƦW�ٻP���O�ܼƦW�ٲŦX
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
					Output->Text += "-Too less input for add function-" + Environment::NewLine;
				}
			}
		}
		//�Ϥ��h�P�_�䤣����O
		else
		{
			Output->Text += "-Command not found-" + Environment::NewLine;
		}
		userInput = "";
	}
	else
	{
		//�N�ϥΪ̿�J�r��(�bText box��)�A��'\n'�@����
		array<String^> ^userCommand = Input->Text->Split('\n');
		//�ñN�̫�@��A�@���ثe�ϥΪ̿�J���O
		userInput = userCommand[userCommand->Length-1];
	}

}
private: System::Void openFileDialog1_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) 
{
	//�bDialog���UOK�K�|�i�J���禡
	//�r�����string^ to string
	std::string tempFileName;
	MarshalString(openFileDialog1->FileName, tempFileName);
	//�N�ɮ׸��|�W�ٶǤJdataManager
	dataManager->SetFileName(tempFileName);
	//�qŪ��Ū���V�q���
	if (dataManager->LoadVectorData())
	{
		//�NVectorList�����إ����M��
		VectorList->Items->Clear();	
		//���o�Ҧ��V�q���
		std::vector<Vector> vectors = dataManager->GetVectors();

		for (unsigned int i = 0; i < vectors.size(); i++)
		{
			//�N�ɮצW�٦s�J�Ȧs
			std::string tempString = vectors[i].getName();
			//�N��X�榡�s�J�Ȧs
			tempString += " [";
			//�N��X��Ʀs�J�Ȧs
			for (unsigned int j = 0; j<vectors[i].getData().size(); j++)
			{
				std::string scalarString = std::to_string(vectors[i].getData()[j]);
				tempString += scalarString.substr(0, scalarString.size() - 5);
				if (j != vectors[i].getData().size() - 1)
					tempString += ",";
			}
			//�N��X�榡�s�J�Ȧs
			tempString += "]";
			//�N���إ[�JVectorList��
			VectorList->Items->Add(gcnew String(tempString.c_str()));
		}
		Output->Text += "-Vector datas have been loaded-" + Environment::NewLine;
	}
}
private: System::Void VectorList_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void loadMatrixToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	//�}��Dialog
	openFileDialog2->ShowDialog();
}
private: System::Void openFileDialog2_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
	//�bDialog���UOK�K�|�i�J���禡
	//�r�����string^ to string
	std::string tempFileName;
	MarshalString(openFileDialog2->FileName, tempFileName);
	//�N�ɮ׸��|�W�ٶǤJdataManager
	dataManager->SetFileName(tempFileName);
	//�qŪ��Ū���V�q���
	if (dataManager->LoadMatrixData())
	{
		//�NVectorList�����إ����M��
		MatrixList->Items->Clear();
		//���o�Ҧ��V�q���
		std::vector<Matrix> matrices = dataManager->GetMatrices();

		for (int i = 0; i < matrices.size(); i++)
		{
			//�N�ɮצW�٦s�J�Ȧs
			std::string tempString = matrices[i].getName();
			//�N��X�榡�s�J�Ȧs
			tempString += " [";
			//�N��X��Ʀs�J�Ȧs
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
			//�N��X�榡�s�J�Ȧs
			tempString += "]";
			//�N���إ[�JVectorList��
			MatrixList->Items->Add(gcnew String(tempString.c_str()));
		}
		Output->Text += "-Matrix datas have been loaded-" + Environment::NewLine;
	}
}

};
}
