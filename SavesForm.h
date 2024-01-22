#pragma once
#include "file.h"
#include "GameForm.h"

namespace RussianLotto {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for SavesForm
	/// </summary>
	public ref class SavesForm : public System::Windows::Forms::Form
	{
	public:
		SavesForm(void)
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
		~SavesForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ profiles_label;
	private: System::Windows::Forms::DataGridView^ dataGrid_profiles;
	private: System::Windows::Forms::Button^ btn_cancel;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;

	protected:


	protected:

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
			this->profiles_label = (gcnew System::Windows::Forms::Label());
			this->dataGrid_profiles = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btn_cancel = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid_profiles))->BeginInit();
			this->SuspendLayout();
			// 
			// profiles_label
			// 
			this->profiles_label->AutoSize = true;
			this->profiles_label->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->profiles_label->Location = System::Drawing::Point(37, 51);
			this->profiles_label->Name = L"profiles_label";
			this->profiles_label->Size = System::Drawing::Size(431, 22);
			this->profiles_label->TabIndex = 2;
			this->profiles_label->Text = L"What profile do You want to load\?";
			// 
			// dataGrid_profiles
			// 
			this->dataGrid_profiles->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGrid_profiles->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGrid_profiles->BackgroundColor = System::Drawing::SystemColors::GradientInactiveCaption;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGrid_profiles->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGrid_profiles->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGrid_profiles->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->dataGridViewTextBoxColumn1 });
			this->dataGrid_profiles->Cursor = System::Windows::Forms::Cursors::Hand;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::ActiveCaption;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGrid_profiles->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGrid_profiles->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->dataGrid_profiles->Location = System::Drawing::Point(127, 98);
			this->dataGrid_profiles->Name = L"dataGrid_profiles";
			this->dataGrid_profiles->ReadOnly = true;
			this->dataGrid_profiles->RowHeadersVisible = false;
			this->dataGrid_profiles->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->dataGrid_profiles->Size = System::Drawing::Size(240, 436);
			this->dataGrid_profiles->TabIndex = 3;
			this->dataGrid_profiles->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &SavesForm::dataGrid_profiles_CellClick);
			this->dataGrid_profiles->MultiSelect = false;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Player";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->ReadOnly = true;
			// 
			// btn_cancel
			// 
			this->btn_cancel->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_cancel->Location = System::Drawing::Point(196, 558);
			this->btn_cancel->Name = L"btn_cancel";
			this->btn_cancel->Size = System::Drawing::Size(100, 30);
			this->btn_cancel->TabIndex = 4;
			this->btn_cancel->Text = L"Cancel";
			this->btn_cancel->UseVisualStyleBackColor = true;
			this->btn_cancel->Click += gcnew System::EventHandler(this, &SavesForm::btn_cancel_Click);
			// 
			// SavesForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(500, 600);
			this->Controls->Add(this->btn_cancel);
			this->Controls->Add(this->dataGrid_profiles);
			this->Controls->Add(this->profiles_label);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"SavesForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"SavesForm";
			this->Load += gcnew System::EventHandler(this, &SavesForm::SavesForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid_profiles))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_cancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void SavesForm_Load(System::Object^ sender, System::EventArgs^ e) {
		File file;
		std::vector<Record> records = file.GetRecords();

		if (records.size() == 0)
			return;

		this->dataGrid_profiles->RowCount = records.size();

		for (int i = 0; i < this->dataGrid_profiles->RowCount; i++)
		{
			this->dataGrid_profiles->Rows[i]->Cells[0]->Value = gcnew System::String(records[i].GetName().c_str());
		}
	}

	private: System::Void dataGrid_profiles_CellClick(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void dataGrid_profiles_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		File file;
		std::vector<Record> records = file.GetRecords();

		std::string selectedProfile;

		for (int i = 0; i < records.size(); i++)
		{
			if (gcnew System::String(records[i].GetName().c_str()) == this->dataGrid_profiles->SelectedCells[0]->Value->ToString())
			{
				selectedProfile = records[i].GetName();

				if (records[i].GetRoundsPassedAmount() == MAX_ROUND_AMOUNT)
				{
					MessageBox::Show(this, "Game over for this player!", "Game over!", MessageBoxButtons::OK, MessageBoxIcon::Information);
					return;
				}
			}
		}
		
		this->Close();

		GameForm gameForm;
		gameForm.LoadGame(selectedProfile);
		gameForm.ShowDialog();
	}
};
}
