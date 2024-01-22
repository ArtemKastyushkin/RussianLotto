#pragma once

#include "file.h"

namespace RussianLotto {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GameSavingForm
	/// </summary>
	public ref class GameSavingForm : public System::Windows::Forms::Form
	{
	public:
		GameSavingForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	public: void SetGame(Game* game) { this->game = game; }

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GameSavingForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_no;

	private: System::Windows::Forms::Button^ btn_yes;
	private: System::Windows::Forms::Label^ save_request;

	private: Game* game = nullptr;

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
			this->btn_no = (gcnew System::Windows::Forms::Button());
			this->btn_yes = (gcnew System::Windows::Forms::Button());
			this->save_request = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btn_no
			// 
			this->btn_no->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_no->Location = System::Drawing::Point(300, 114);
			this->btn_no->Name = L"btn_no";
			this->btn_no->Size = System::Drawing::Size(100, 30);
			this->btn_no->TabIndex = 7;
			this->btn_no->Text = L"No";
			this->btn_no->UseVisualStyleBackColor = true;
			this->btn_no->Click += gcnew System::EventHandler(this, &GameSavingForm::btn_no_Click);
			// 
			// btn_yes
			// 
			this->btn_yes->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_yes->Location = System::Drawing::Point(107, 114);
			this->btn_yes->Name = L"btn_yes";
			this->btn_yes->Size = System::Drawing::Size(100, 30);
			this->btn_yes->TabIndex = 6;
			this->btn_yes->Text = L"Yes";
			this->btn_yes->UseVisualStyleBackColor = true;
			this->btn_yes->Click += gcnew System::EventHandler(this, &GameSavingForm::btn_yes_Click);
			// 
			// save_request
			// 
			this->save_request->AutoSize = true;
			this->save_request->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->save_request->Location = System::Drawing::Point(43, 52);
			this->save_request->Name = L"save_request";
			this->save_request->Size = System::Drawing::Size(415, 19);
			this->save_request->TabIndex = 4;
			this->save_request->Text = L"Do You want to save Your Progress\?";
			// 
			// GameSavingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(500, 200);
			this->Controls->Add(this->btn_no);
			this->Controls->Add(this->btn_yes);
			this->Controls->Add(this->save_request);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"GameSavingForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"GameSavingForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_no_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void btn_yes_Click(System::Object^ sender, System::EventArgs^ e) {
		if (game)
		{
			File file;

			file.Save(game);
			file.SaveRecord(Record(game->GetUserName(), game->GetUserBalance(), game->GetRoundsCount() - 1));

			game = nullptr;
		}

		this->Close();
	}
};
}
