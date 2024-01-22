#pragma once
#include "file.h";

namespace RussianLotto {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for RecordsForm
	/// </summary>
	public ref class RecordsForm : public System::Windows::Forms::Form
	{
	public:
		RecordsForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RecordsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGrid_records;
	protected:

	protected:

	protected:
	private: System::Windows::Forms::Label^ records_label;
	private: System::Windows::Forms::Button^ btn_exit;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->dataGrid_records = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->records_label = (gcnew System::Windows::Forms::Label());
			this->btn_exit = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid_records))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGrid_records
			// 
			this->dataGrid_records->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGrid_records->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGrid_records->BackgroundColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGrid_records->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGrid_records->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGrid_records->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3
			});
			this->dataGrid_records->Cursor = System::Windows::Forms::Cursors::Default;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGrid_records->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGrid_records->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->dataGrid_records->Location = System::Drawing::Point(250, 132);
			this->dataGrid_records->Name = L"dataGrid_records";
			this->dataGrid_records->RowHeadersVisible = false;
			this->dataGrid_records->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGrid_records->Size = System::Drawing::Size(800, 422);
			this->dataGrid_records->TabIndex = 0;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Player";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Score";
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Levels Passed";
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			// 
			// records_label
			// 
			this->records_label->AutoSize = true;
			this->records_label->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->records_label->Location = System::Drawing::Point(562, 63);
			this->records_label->Name = L"records_label";
			this->records_label->Size = System::Drawing::Size(168, 34);
			this->records_label->TabIndex = 1;
			this->records_label->Text = L"Records";
			// 
			// btn_exit
			// 
			this->btn_exit->AutoSize = true;
			this->btn_exit->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->btn_exit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_exit->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_exit->Location = System::Drawing::Point(86, 583);
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->Size = System::Drawing::Size(167, 45);
			this->btn_exit->TabIndex = 17;
			this->btn_exit->Text = L"Exit";
			this->btn_exit->UseVisualStyleBackColor = false;
			this->btn_exit->Click += gcnew System::EventHandler(this, &RecordsForm::btn_exit_Click);
			// 
			// RecordsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(15, 22);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->ClientSize = System::Drawing::Size(1280, 720);
			this->Controls->Add(this->btn_exit);
			this->Controls->Add(this->records_label);
			this->Controls->Add(this->dataGrid_records);
			this->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(8, 5, 8, 5);
			this->Name = L"RecordsForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RecordsForm";
			this->Load += gcnew System::EventHandler(this, &RecordsForm::RecordsForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid_records))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_exit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void RecordsForm_Load(System::Object^ sender, System::EventArgs^ e) {
		File file;
		std::vector<Record> records = file.GetRecords();

		if (records.size() == 0)
			return;

		this->dataGrid_records->RowCount = records.size();

		for (int i = 0; i < this->dataGrid_records->RowCount; i++)
		{
			this->dataGrid_records->Rows[i]->Cells[0]->Value = gcnew System::String(records[i].GetName().c_str());
			this->dataGrid_records->Rows[i]->Cells[1]->Value = records[i].GetScore();
			this->dataGrid_records->Rows[i]->Cells[2]->Value = records[i].GetRoundsPassedAmount();
		}
	}
};
}
