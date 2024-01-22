#pragma once
#include <string>
#include <iostream>
#include "game.h"
#include "GameSavingForm.h"

namespace RussianLotto {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// Summary for GameForm
	/// </summary>
	public ref class GameForm : public System::Windows::Forms::Form
	{
	public:
		GameForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	public: void CreateGame(std::string humanName)
	{
		game = new Game(humanName);

		game->NextRound();
		game->ShowPlayersCard(this->dataGrid_human, this->dataGrid_computer);

		UpdateNickname(gcnew System::String(game->GetUserName().c_str()));

		UpdateData();
	}

	public: void LoadGame(std::string humanName)
	{
		File file;

		game = new Game{ file.Load(humanName) };

		game->NextRound();
		game->ShowPlayersCard(this->dataGrid_human, this->dataGrid_computer);

		UpdateNickname(gcnew System::String(game->GetUserName().c_str()));

		UpdateData();
	}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GameForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: void UpdateData()
	{
		UpdateBank(game->GetBank());
		UpdateRoundsCount(game->GetRoundsCount());
		UpdateUserBalance(game->GetUserBalance());
	}

	private: System::Windows::Forms::DataGridView^ dataGrid_human;
	private: System::Windows::Forms::Label^ human_nickname;
	private: System::Windows::Forms::Label^ computer_nickname;
	private: System::Windows::Forms::Label^ round_label;

	private: System::Windows::Forms::Label^ balance_label;


	private: System::Windows::Forms::Label^ balance_amount;
	private: System::Windows::Forms::Label^ round_count;

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn10;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn11;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn12;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn13;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn14;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn15;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn16;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn17;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn18;
	private: System::Windows::Forms::TextBox^ numbers_box;
	private: System::Windows::Forms::DataGridView^ dataGrid_computer;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn9;
	private: System::Windows::Forms::Label^ bank_label;
	private: System::Windows::Forms::Label^ bank_amount;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn25;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn26;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn27;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn28;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn29;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn30;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn19;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn20;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn21;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn22;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn23;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn24;
	private: System::Windows::Forms::TextBox^ keg_box;
	private: System::Windows::Forms::Button^ btn_start;
	private: System::Windows::Forms::Button^ btn_next_round;
	private: System::Windows::Forms::Button^ btn_exit;

	private: Game* game;

	private: void MarshalString(String^ s, string& os) 
	{
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
	}

	private: void UpdateNickname(String^ humanName) { this->human_nickname->Text = humanName; }

	private: void UpdateBank(int bank) { this->bank_amount->Text = bank.ToString(); }

	private: void UpdateRoundsCount(int roundCount) { this->round_count->Text = roundCount.ToString(); }

	private: void UpdateUserBalance(int balance) { this->balance_amount->Text = balance.ToString(); }

	private: void ClearFields()
	{
		this->numbers_box->Text = "";

		this->keg_box->Text = "";

		for (int i = 0; i < this->dataGrid_human->RowCount; i++)
		{
			for (int j = 0; j < this->dataGrid_human->ColumnCount; j++)
			{
				this->dataGrid_human->Rows[i]->Cells[j]->Value = "";
				this->dataGrid_computer->Rows[i]->Cells[j]->Value = "";
			}
		}
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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(GameForm::typeid));
			this->dataGrid_human = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn12 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn25 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn26 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn27 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn28 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn29 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn30 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn13 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn14 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn15 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn16 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn17 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn18 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->human_nickname = (gcnew System::Windows::Forms::Label());
			this->computer_nickname = (gcnew System::Windows::Forms::Label());
			this->round_label = (gcnew System::Windows::Forms::Label());
			this->balance_label = (gcnew System::Windows::Forms::Label());
			this->balance_amount = (gcnew System::Windows::Forms::Label());
			this->round_count = (gcnew System::Windows::Forms::Label());
			this->numbers_box = (gcnew System::Windows::Forms::TextBox());
			this->dataGrid_computer = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn19 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn20 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn21 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn22 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn23 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn24 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->bank_label = (gcnew System::Windows::Forms::Label());
			this->bank_amount = (gcnew System::Windows::Forms::Label());
			this->keg_box = (gcnew System::Windows::Forms::TextBox());
			this->btn_start = (gcnew System::Windows::Forms::Button());
			this->btn_next_round = (gcnew System::Windows::Forms::Button());
			this->btn_exit = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid_human))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid_computer))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGrid_human
			// 
			this->dataGrid_human->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGrid_human->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->dataGrid_human->BackgroundColor = System::Drawing::SystemColors::InactiveCaption;
			this->dataGrid_human->ColumnHeadersHeight = 70;
			this->dataGrid_human->ColumnHeadersVisible = false;
			this->dataGrid_human->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->dataGridViewTextBoxColumn10,
					this->dataGridViewTextBoxColumn11, this->dataGridViewTextBoxColumn12, this->dataGridViewTextBoxColumn25, this->dataGridViewTextBoxColumn26,
					this->dataGridViewTextBoxColumn27, this->dataGridViewTextBoxColumn28, this->dataGridViewTextBoxColumn29, this->dataGridViewTextBoxColumn30
			});
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGrid_human->DefaultCellStyle = dataGridViewCellStyle1;
			this->dataGrid_human->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->dataGrid_human->Enabled = false;
			this->dataGrid_human->EnableHeadersVisualStyles = false;
			this->dataGrid_human->Location = System::Drawing::Point(103, 215);
			this->dataGrid_human->Name = L"dataGrid_human";
			this->dataGrid_human->RowHeadersVisible = false;
			this->dataGrid_human->RowHeadersWidth = 20;
			this->dataGrid_human->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGrid_human->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGrid_human->ShowEditingIcon = false;
			this->dataGrid_human->Size = System::Drawing::Size(400, 80);
			this->dataGrid_human->TabIndex = 0;
			this->dataGrid_human->RowCount = 3;
			this->dataGrid_human->ColumnCount = 9;
			// 
			// dataGridViewTextBoxColumn10
			// 
			this->dataGridViewTextBoxColumn10->Name = L"dataGridViewTextBoxColumn10";
			// 
			// dataGridViewTextBoxColumn11
			// 
			this->dataGridViewTextBoxColumn11->Name = L"dataGridViewTextBoxColumn11";
			// 
			// dataGridViewTextBoxColumn12
			// 
			this->dataGridViewTextBoxColumn12->Name = L"dataGridViewTextBoxColumn12";
			// 
			// dataGridViewTextBoxColumn25
			// 
			this->dataGridViewTextBoxColumn25->Name = L"dataGridViewTextBoxColumn25";
			// 
			// dataGridViewTextBoxColumn26
			// 
			this->dataGridViewTextBoxColumn26->Name = L"dataGridViewTextBoxColumn26";
			// 
			// dataGridViewTextBoxColumn27
			// 
			this->dataGridViewTextBoxColumn27->Name = L"dataGridViewTextBoxColumn27";
			// 
			// dataGridViewTextBoxColumn28
			// 
			this->dataGridViewTextBoxColumn28->Name = L"dataGridViewTextBoxColumn28";
			// 
			// dataGridViewTextBoxColumn29
			// 
			this->dataGridViewTextBoxColumn29->Name = L"dataGridViewTextBoxColumn29";
			// 
			// dataGridViewTextBoxColumn30
			// 
			this->dataGridViewTextBoxColumn30->Name = L"dataGridViewTextBoxColumn30";
			// 
			// dataGridViewTextBoxColumn13
			// 
			this->dataGridViewTextBoxColumn13->Name = L"dataGridViewTextBoxColumn13";
			// 
			// dataGridViewTextBoxColumn14
			// 
			this->dataGridViewTextBoxColumn14->Name = L"dataGridViewTextBoxColumn14";
			// 
			// dataGridViewTextBoxColumn15
			// 
			this->dataGridViewTextBoxColumn15->Name = L"dataGridViewTextBoxColumn15";
			// 
			// dataGridViewTextBoxColumn16
			// 
			this->dataGridViewTextBoxColumn16->Name = L"dataGridViewTextBoxColumn16";
			// 
			// dataGridViewTextBoxColumn17
			// 
			this->dataGridViewTextBoxColumn17->Name = L"dataGridViewTextBoxColumn17";
			// 
			// dataGridViewTextBoxColumn18
			// 
			this->dataGridViewTextBoxColumn18->Name = L"dataGridViewTextBoxColumn18";
			// 
			// human_nickname
			// 
			this->human_nickname->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->human_nickname->Location = System::Drawing::Point(99, 172);
			this->human_nickname->Name = L"human_nickname";
			this->human_nickname->Size = System::Drawing::Size(150, 30);
			this->human_nickname->TabIndex = 2;
			this->human_nickname->Text = L"Player";
			// 
			// computer_nickname
			// 
			this->computer_nickname->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->computer_nickname->Location = System::Drawing::Point(755, 172);
			this->computer_nickname->Name = L"computer_nickname";
			this->computer_nickname->Size = System::Drawing::Size(150, 30);
			this->computer_nickname->TabIndex = 3;
			this->computer_nickname->Text = L"Computer";
			// 
			// round_label
			// 
			this->round_label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->round_label->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->round_label->Location = System::Drawing::Point(565, 98);
			this->round_label->Name = L"round_label";
			this->round_label->Size = System::Drawing::Size(120, 30);
			this->round_label->TabIndex = 4;
			this->round_label->Text = L"ROUND";
			this->round_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// balance_label
			// 
			this->balance_label->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->balance_label->Location = System::Drawing::Point(30, 31);
			this->balance_label->Name = L"balance_label";
			this->balance_label->Size = System::Drawing::Size(105, 30);
			this->balance_label->TabIndex = 5;
			this->balance_label->Text = L"Balance: 0";
			// 
			// balance_amount
			// 
			this->balance_amount->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->balance_amount->Location = System::Drawing::Point(126, 31);
			this->balance_amount->Name = L"balance_amount";
			this->balance_amount->Size = System::Drawing::Size(105, 30);
			this->balance_amount->TabIndex = 7;
			this->balance_amount->Text = L"100";
			// 
			// round_count
			// 
			this->round_count->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->round_count->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->round_count->Location = System::Drawing::Point(680, 98);
			this->round_count->Name = L"round_count";
			this->round_count->Size = System::Drawing::Size(120, 30);
			this->round_count->TabIndex = 8;
			this->round_count->Text = L"1";
			this->round_count->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// numbers_box
			// 
			this->numbers_box->Cursor = System::Windows::Forms::Cursors::Default;
			this->numbers_box->Enabled = false;
			this->numbers_box->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numbers_box->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->numbers_box->Location = System::Drawing::Point(103, 411);
			this->numbers_box->Multiline = true;
			this->numbers_box->Name = L"numbers_box";
			this->numbers_box->ReadOnly = true;
			this->numbers_box->Size = System::Drawing::Size(1056, 143);
			this->numbers_box->TabIndex = 9;
			// 
			// dataGrid_computer
			// 
			this->dataGrid_computer->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGrid_computer->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedCells;
			this->dataGrid_computer->BackgroundColor = System::Drawing::SystemColors::InactiveCaption;
			this->dataGrid_computer->ColumnHeadersHeight = 70;
			this->dataGrid_computer->ColumnHeadersVisible = false;
			this->dataGrid_computer->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(9) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->dataGridViewTextBoxColumn19, this->dataGridViewTextBoxColumn20,
					this->dataGridViewTextBoxColumn21, this->dataGridViewTextBoxColumn22, this->dataGridViewTextBoxColumn23, this->dataGridViewTextBoxColumn24
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGrid_computer->DefaultCellStyle = dataGridViewCellStyle2;
			this->dataGrid_computer->EditMode = System::Windows::Forms::DataGridViewEditMode::EditProgrammatically;
			this->dataGrid_computer->Enabled = false;
			this->dataGrid_computer->EnableHeadersVisualStyles = false;
			this->dataGrid_computer->Location = System::Drawing::Point(759, 215);
			this->dataGrid_computer->Name = L"dataGrid_computer";
			this->dataGrid_computer->RowHeadersVisible = false;
			this->dataGrid_computer->RowHeadersWidth = 20;
			this->dataGrid_computer->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGrid_computer->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::CellSelect;
			this->dataGrid_computer->ShowEditingIcon = false;
			this->dataGrid_computer->Size = System::Drawing::Size(400, 80);
			this->dataGrid_computer->TabIndex = 10;
			this->dataGrid_computer->RowCount = 3;
			this->dataGrid_computer->ColumnCount = 9;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			// 
			// dataGridViewTextBoxColumn19
			// 
			this->dataGridViewTextBoxColumn19->Name = L"dataGridViewTextBoxColumn19";
			// 
			// dataGridViewTextBoxColumn20
			// 
			this->dataGridViewTextBoxColumn20->Name = L"dataGridViewTextBoxColumn20";
			// 
			// dataGridViewTextBoxColumn21
			// 
			this->dataGridViewTextBoxColumn21->Name = L"dataGridViewTextBoxColumn21";
			// 
			// dataGridViewTextBoxColumn22
			// 
			this->dataGridViewTextBoxColumn22->Name = L"dataGridViewTextBoxColumn22";
			// 
			// dataGridViewTextBoxColumn23
			// 
			this->dataGridViewTextBoxColumn23->Name = L"dataGridViewTextBoxColumn23";
			// 
			// dataGridViewTextBoxColumn24
			// 
			this->dataGridViewTextBoxColumn24->Name = L"dataGridViewTextBoxColumn24";
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			// 
			// dataGridViewTextBoxColumn7
			// 
			this->dataGridViewTextBoxColumn7->Name = L"dataGridViewTextBoxColumn7";
			// 
			// dataGridViewTextBoxColumn8
			// 
			this->dataGridViewTextBoxColumn8->Name = L"dataGridViewTextBoxColumn8";
			// 
			// dataGridViewTextBoxColumn9
			// 
			this->dataGridViewTextBoxColumn9->Name = L"dataGridViewTextBoxColumn9";
			// 
			// bank_label
			// 
			this->bank_label->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bank_label->Location = System::Drawing::Point(1130, 31);
			this->bank_label->Name = L"bank_label";
			this->bank_label->Size = System::Drawing::Size(69, 30);
			this->bank_label->TabIndex = 11;
			this->bank_label->Text = L"Bank:";
			// 
			// bank_amount
			// 
			this->bank_amount->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bank_amount->Location = System::Drawing::Point(1192, 31);
			this->bank_amount->Name = L"bank_amount";
			this->bank_amount->Size = System::Drawing::Size(60, 30);
			this->bank_amount->TabIndex = 12;
			this->bank_amount->Text = L"20";
			// 
			// keg_box
			// 
			this->keg_box->Cursor = System::Windows::Forms::Cursors::Default;
			this->keg_box->Enabled = false;
			this->keg_box->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->keg_box->Location = System::Drawing::Point(609, 242);
			this->keg_box->Name = L"keg_box";
			this->keg_box->ReadOnly = true;
			this->keg_box->Size = System::Drawing::Size(58, 29);
			this->keg_box->TabIndex = 13;
			this->keg_box->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// btn_start
			// 
			this->btn_start->AutoSize = true;
			this->btn_start->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->btn_start->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_start->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_start->Location = System::Drawing::Point(562, 582);
			this->btn_start->Name = L"btn_start";
			this->btn_start->Size = System::Drawing::Size(167, 45);
			this->btn_start->TabIndex = 14;
			this->btn_start->Text = L"Start Game";
			this->btn_start->UseVisualStyleBackColor = false;
			this->btn_start->Click += gcnew System::EventHandler(this, &GameForm::btn_start_Click);
			// 
			// btn_next_round
			// 
			this->btn_next_round->AutoSize = true;
			this->btn_next_round->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->btn_next_round->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_next_round->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_next_round->Location = System::Drawing::Point(992, 582);
			this->btn_next_round->Name = L"btn_next_round";
			this->btn_next_round->Size = System::Drawing::Size(167, 45);
			this->btn_next_round->TabIndex = 15;
			this->btn_next_round->Text = L"Next Round";
			this->btn_next_round->UseVisualStyleBackColor = false;
			this->btn_next_round->Visible = false;
			this->btn_next_round->Click += gcnew System::EventHandler(this, &GameForm::btn_next_round_Click);
			// 
			// btn_exit
			// 
			this->btn_exit->AutoSize = true;
			this->btn_exit->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->btn_exit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_exit->Font = (gcnew System::Drawing::Font(L"BankGothic Md BT", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_exit->Location = System::Drawing::Point(103, 582);
			this->btn_exit->Name = L"btn_exit";
			this->btn_exit->Size = System::Drawing::Size(167, 45);
			this->btn_exit->TabIndex = 16;
			this->btn_exit->Text = L"Exit";
			this->btn_exit->UseVisualStyleBackColor = false;
			this->btn_exit->Visible = false;
			this->btn_exit->Click += gcnew System::EventHandler(this, &GameForm::btn_exit_Click);
			// 
			// GameForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->ClientSize = System::Drawing::Size(1280, 720);
			this->Controls->Add(this->btn_exit);
			this->Controls->Add(this->btn_next_round);
			this->Controls->Add(this->btn_start);
			this->Controls->Add(this->keg_box);
			this->Controls->Add(this->bank_amount);
			this->Controls->Add(this->bank_label);
			this->Controls->Add(this->dataGrid_computer);
			this->Controls->Add(this->numbers_box);
			this->Controls->Add(this->round_count);
			this->Controls->Add(this->balance_amount);
			this->Controls->Add(this->balance_label);
			this->Controls->Add(this->round_label);
			this->Controls->Add(this->computer_nickname);
			this->Controls->Add(this->human_nickname);
			this->Controls->Add(this->dataGrid_human);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"GameForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L" ";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid_human))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGrid_computer))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_start_Click(System::Object^ sender, System::EventArgs^ e) {
		this->btn_start->Visible = false;

		while (!game->HasWinner())
		{
			System::String^ keg = game->GetKeg().ToString();
			this->keg_box->Text = keg;

			if (this->numbers_box->Text->Length == 0)
				this->numbers_box->Text = keg;
			else
				this->numbers_box->Text += ", " + keg;

			game->ShowPlayersCard(this->dataGrid_human, this->dataGrid_computer);
		}

		UpdateBank(game->GetBank());
		UpdateUserBalance(game->GetUserBalance());

		this->btn_exit->Visible = true;
		this->btn_next_round->Visible = true;

		MessageBox::Show(this, "The winner is " + gcnew System::String(game->GetWinnerName().c_str()), "Round is over", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	private: System::Void btn_next_round_Click(System::Object^ sender, System::EventArgs^ e) {
		if (game->GetRoundsCount() > MAX_ROUND_AMOUNT)
		{
			MessageBox::Show(this, "Game over!", "Game over!", MessageBoxButtons::OK, MessageBoxIcon::Information);
			return;
		}

		this->btn_exit->Visible = false;
		this->btn_next_round->Visible = false;
		this->btn_start->Visible = true;

		game->NextRound();

		ClearFields();

		game->ShowPlayersCard(this->dataGrid_human, this->dataGrid_computer);
		UpdateData();
	}
	private: System::Void btn_exit_Click(System::Object^ sender, System::EventArgs^ e) {
		GameSavingForm gameSavingForm;
		gameSavingForm.SetGame(game);
		gameSavingForm.ShowDialog();

		this->Close();
	}
};
}