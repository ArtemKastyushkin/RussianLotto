#pragma once
#include "GameForm.h"
#include <iostream>

namespace RussianLotto {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GameCreationForm
	/// </summary>
	public ref class GameCreationForm : public System::Windows::Forms::Form
	{
	public:
		GameCreationForm(void)
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
		~GameCreationForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ nickname_request;
	private: System::Windows::Forms::TextBox^ nickname_textbox;


	private: System::Windows::Forms::Button^ btn_cancel;
	private: System::Windows::Forms::Button^ btn_accept;

	private: void MarshalString(String^ s, string& os)
	{
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

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
			this->nickname_request = (gcnew System::Windows::Forms::Label());
			this->nickname_textbox = (gcnew System::Windows::Forms::TextBox());
			this->btn_cancel = (gcnew System::Windows::Forms::Button());
			this->btn_accept = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// nickname_request
			// 
			this->nickname_request->AutoSize = true;
			this->nickname_request->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nickname_request->Location = System::Drawing::Point(134, 24);
			this->nickname_request->Name = L"nickname_request";
			this->nickname_request->Size = System::Drawing::Size(238, 19);
			this->nickname_request->TabIndex = 0;
			this->nickname_request->Text = L"Enter Your Nickname";
			// 
			// nickname_textbox
			// 
			this->nickname_textbox->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nickname_textbox->Location = System::Drawing::Point(76, 69);
			this->nickname_textbox->Name = L"nickname_textbox";
			this->nickname_textbox->Size = System::Drawing::Size(350, 27);
			this->nickname_textbox->TabIndex = 1;
			// 
			// btn_cancel
			// 
			this->btn_cancel->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_cancel->Location = System::Drawing::Point(76, 138);
			this->btn_cancel->Name = L"btn_cancel";
			this->btn_cancel->Size = System::Drawing::Size(100, 30);
			this->btn_cancel->TabIndex = 2;
			this->btn_cancel->Text = L"Cancel";
			this->btn_cancel->UseVisualStyleBackColor = true;
			this->btn_cancel->Click += gcnew System::EventHandler(this, &GameCreationForm::btn_cancel_Click);
			// 
			// btn_accept
			// 
			this->btn_accept->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_accept->Location = System::Drawing::Point(326, 138);
			this->btn_accept->Name = L"btn_accept";
			this->btn_accept->Size = System::Drawing::Size(100, 30);
			this->btn_accept->TabIndex = 3;
			this->btn_accept->Text = L"Accept";
			this->btn_accept->UseVisualStyleBackColor = true;
			this->btn_accept->Click += gcnew System::EventHandler(this, &GameCreationForm::btn_accept_Click);
			// 
			// GameCreationForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(500, 200);
			this->Controls->Add(this->btn_accept);
			this->Controls->Add(this->btn_cancel);
			this->Controls->Add(this->nickname_textbox);
			this->Controls->Add(this->nickname_request);
			this->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Name = L"GameCreationForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"GameCreationForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_cancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}

	private: System::Void btn_accept_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ nickname = this->nickname_textbox->Text;

		if (!String::IsNullOrEmpty(nickname))
		{
			string convertedName;
			MarshalString(nickname, convertedName);

			File file;

			if (file.IsUserExist(convertedName))
			{
				MessageBox::Show(this, "This user already exists!", "Incorrect nickname!", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			this->Hide();
			GameForm gameForm;
			gameForm.CreateGame(convertedName);
			gameForm.ShowDialog();
		}
		else
		{
			MessageBox::Show(this, "The nickname field is empty!", "Incorrect nickname!", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
};
}
