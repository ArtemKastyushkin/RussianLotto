#pragma once
#include "GameCreationForm.h"
#include "RecordsForm.h"
#include "SavesForm.h"

namespace RussianLotto {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_new_game;
	private: System::Windows::Forms::Button^ btn_load_game;
	private: System::Windows::Forms::Button^ btn_records;
	private: System::Windows::Forms::Button^ btn_exit;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->btn_new_game = (gcnew System::Windows::Forms::Button());
			this->btn_load_game = (gcnew System::Windows::Forms::Button());
			this->btn_records = (gcnew System::Windows::Forms::Button());
			this->btn_exit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_new_game
			// 
			this->btn_new_game->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_new_game->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->btn_new_game->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_new_game->FlatAppearance->BorderSize = 0;
			this->btn_new_game->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_new_game->Location = System::Drawing::Point(455, 168);
			this->btn_new_game->Margin = System::Windows::Forms::Padding(0);
			this->btn_new_game->Name = L"btn_new_game";
			this->btn_new_game->Size = System::Drawing::Size(346, 46);
			this->btn_new_game->TabIndex = 0;
			this->btn_new_game->Text = L"New Game";
			this->btn_new_game->UseVisualStyleBackColor = false;
			this->btn_new_game->Click += gcnew System::EventHandler(this, &MainForm::btn_new_game_Click);
			// 
			// btn_load_game
			// 
			this->btn_load_game->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_load_game->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->btn_load_game->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_load_game->FlatAppearance->BorderSize = 0;
			this->btn_load_game->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_load_game->Location = System::Drawing::Point(455, 254);
			this->btn_load_game->Margin = System::Windows::Forms::Padding(0);
			this->btn_load_game->Name = L"btn_load_game";
			this->btn_load_game->Size = System::Drawing::Size(346, 46);
			this->btn_load_game->TabIndex = 1;
			this->btn_load_game->Text = L"Load Game";
			this->btn_load_game->UseVisualStyleBackColor = false;
			this->btn_load_game->Click += gcnew System::EventHandler(this, &MainForm::btn_load_game_Click);
			// 
			// btn_records
			// 
			this->btn_records->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_records->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->btn_records->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_records->FlatAppearance->BorderSize = 0;
			this->btn_records->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_records->Location = System::Drawing::Point(455, 339);
			this->btn_records->Margin = System::Windows::Forms::Padding(0);
			this->btn_records->Name = L"btn_records";
			this->btn_records->Size = System::Drawing::Size(346, 46);
			this->btn_records->TabIndex = 2;
			this->btn_records->Text = L"Records";
			this->btn_records->UseVisualStyleBackColor = false;
			this->btn_records->Click += gcnew System::EventHandler(this, &MainForm::btn_records_Click);
			// 
			// btn_exit
			// 
			this->btn_exit->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->btn_exit->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->btn_exit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_exit->FlatAppearance->BorderSize = 0;
			this->btn_exit->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_exit->Location = System::Drawing::Point(455, 424);
			this->btn_exit->Margin = System::Windows::Forms::Padding(0);
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->Size = System::Drawing::Size(346, 46);
			this->btn_exit->TabIndex = 3;
			this->btn_exit->Text = L"Exit";
			this->btn_exit->UseVisualStyleBackColor = false;
			this->btn_exit->Click += gcnew System::EventHandler(this, &MainForm::btn_exit_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->ClientSize = System::Drawing::Size(1280, 720);
			this->Controls->Add(this->btn_exit);
			this->Controls->Add(this->btn_records);
			this->Controls->Add(this->btn_load_game);
			this->Controls->Add(this->btn_new_game);
			this->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Russian Lotto";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btn_exit_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void btn_new_game_Click(System::Object^ sender, System::EventArgs^ e) {
		GameCreationForm gameCreationForm;
		gameCreationForm.ShowDialog();
	}
	private: System::Void btn_load_game_Click(System::Object^ sender, System::EventArgs^ e) {
		SavesForm savesForm;
		savesForm.ShowDialog();
	}

	private: System::Void btn_records_Click(System::Object^ sender, System::EventArgs^ e) {
		RecordsForm recordsForm;
		recordsForm.ShowDialog();
	}
};
}
