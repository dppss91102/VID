#pragma once
#include <stdio.h>
#include <string>

#include ".\ALP_resource\ALP_parameter.h"

static long nPictureTime = 852.5;//us 852.5

tAlpProjProgress	projProgress;
tAlpProjProgress	*projPtr;
ALP_ID			nDevId, nSeqId[100];
UCHAR			*pImageData=NULL;
bool			sent = false;

bool started = false;

int T=0; //sequence control
static int X=100,Y=100;
static bool Btn=true;//true for Move

namespace VID {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor                                                                                                code here
			//

			str = "";
		}
		String^ str;
	private: System::Windows::Forms::Button^  button_stop;
	private: System::Windows::Forms::Label^  label_PictureTime;

	private: System::Windows::Forms::TrackBar^  trackBar1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;

	public: 
		static array<String^>^ num = gcnew array<String^>{"10"};
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected: 
	private: System::Windows::Forms::Label^  Label_XY;
	private: System::Windows::Forms::Timer^  timer;


	private: System::Windows::Forms::Button^  button_Move;
	private: System::Windows::Forms::Button^  button_Jump;
	private: System::IO::Ports::SerialPort^  serialPort1;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->Label_XY = (gcnew System::Windows::Forms::Label());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->button_Move = (gcnew System::Windows::Forms::Button());
			this->button_Jump = (gcnew System::Windows::Forms::Button());
			this->serialPort1 = (gcnew System::IO::Ports::SerialPort(this->components));
			this->button_stop = (gcnew System::Windows::Forms::Button());
			this->label_PictureTime = (gcnew System::Windows::Forms::Label());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->pictureBox1->Location = System::Drawing::Point(12, 37);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(230, 340);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::pictureBox1_MouseMove);
			// 
			// Label_XY
			// 
			this->Label_XY->AutoSize = true;
			this->Label_XY->Location = System::Drawing::Point(13, 13);
			this->Label_XY->Name = L"Label_XY";
			this->Label_XY->Size = System::Drawing::Size(61, 12);
			this->Label_XY->TabIndex = 1;
			this->Label_XY->Text = L"Coordinates";
			// 
			// timer
			// 
			this->timer->Interval = 10;
			this->timer->Tick += gcnew System::EventHandler(this, &Form1::timer_Tick);
			// 
			// button_Move
			// 
			this->button_Move->BackColor = System::Drawing::Color::SeaShell;
			this->button_Move->Location = System::Drawing::Point(248, 37);
			this->button_Move->Name = L"button_Move";
			this->button_Move->Size = System::Drawing::Size(66, 41);
			this->button_Move->TabIndex = 2;
			this->button_Move->Text = L"Move";
			this->button_Move->UseVisualStyleBackColor = false;
			this->button_Move->Click += gcnew System::EventHandler(this, &Form1::button_Move_Click);
			// 
			// button_Jump
			// 
			this->button_Jump->BackColor = System::Drawing::Color::SeaShell;
			this->button_Jump->Enabled = false;
			this->button_Jump->Location = System::Drawing::Point(248, 98);
			this->button_Jump->Name = L"button_Jump";
			this->button_Jump->Size = System::Drawing::Size(66, 41);
			this->button_Jump->TabIndex = 2;
			this->button_Jump->Text = L"Jump";
			this->button_Jump->UseVisualStyleBackColor = false;
			this->button_Jump->Click += gcnew System::EventHandler(this, &Form1::button_Jump_Click);
			// 
			// serialPort1
			// 
			this->serialPort1->PortName = L"COM3";
			this->serialPort1->DataReceived += gcnew System::IO::Ports::SerialDataReceivedEventHandler(this, &Form1::serialPort1_DataReceived);
			// 
			// button_stop
			// 
			this->button_stop->BackColor = System::Drawing::Color::Red;
			this->button_stop->Enabled = false;
			this->button_stop->Location = System::Drawing::Point(248, 290);
			this->button_stop->Name = L"button_stop";
			this->button_stop->Size = System::Drawing::Size(66, 41);
			this->button_stop->TabIndex = 2;
			this->button_stop->Text = L"Stop";
			this->button_stop->UseVisualStyleBackColor = false;
			// 
			// label_PictureTime
			// 
			this->label_PictureTime->AutoSize = true;
			this->label_PictureTime->Location = System::Drawing::Point(13, 427);
			this->label_PictureTime->Name = L"label_PictureTime";
			this->label_PictureTime->Size = System::Drawing::Size(0, 12);
			this->label_PictureTime->TabIndex = 3;
			// 
			// trackBar1
			// 
			this->trackBar1->Location = System::Drawing::Point(81, 427);
			this->trackBar1->Maximum = 18000;
			this->trackBar1->Minimum = 1;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(233, 45);
			this->trackBar1->TabIndex = 4;
			this->trackBar1->Value = 3000;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &Form1::trackBar1_Scroll);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"新細明體", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(136)));
			this->label1->Location = System::Drawing::Point(247, 357);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(43, 48);
			this->label1->TabIndex = 5;
			this->label1->Text = L"0";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(255, 170);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(34, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"+";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(255, 199);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(34, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"-";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LightSteelBlue;
			this->ClientSize = System::Drawing::Size(316, 455);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->label_PictureTime);
			this->Controls->Add(this->button_stop);
			this->Controls->Add(this->button_Jump);
			this->Controls->Add(this->button_Move);
			this->Controls->Add(this->Label_XY);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) 
		 {
			 serialPort1->Open();
			 if (ALP_OK != AlpDevAlloc( ALP_DEFAULT, ALP_DEFAULT, &nDevId )) return;
			 //改成SLAVE_MODE !!!!!
			 if (ALP_OK != AlpProjControl( nDevId, ALP_PROJ_MODE, ALP_SLAVE )) return ;
			 trackBar1->Value=850;
			 
			 projPtr=&projProgress;
			  
			 timer->Enabled = true;
		 }
private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e) 
		 {
			 trackBar1->Value = nPictureTime;
				  if (str->CompareTo("s")==1)
				  {
					pImageData = (UCHAR*) malloc( PicNum*nSizeX*nSizeY );
				  //AlpProjInquireEx(nDevId,ALP_PROJ_PROGRESS,projPtr);
				  //int uu = projPtr->nFrameCounter;
				  //label1->Text=uu.ToString();
				  
				  //AlpDevHalt(nDevId);
				  AlpProjControl(nDevId,ALP_PROJ_ABORT_FRAME,nSeqId[T]);//stop the last sequence
				  AlpSeqFree(nDevId,nSeqId[T]);

				  T++;
				  if(T==100) T=0;


				  if (ALP_OK != AlpSeqAlloc( nDevId, 1, PicNum, &nSeqId[T] )) return ;

				  FillMemory( pImageData, PicNum*nSizeX*nSizeY, 0x00 ); 

				  if (Btn)//true for Move
				  {
					MemoryMove(pImageData);
				  }
				  else
				  {
					MemoryJump(pImageData);
				  }

				  Mouse(pImageData,X,Y);

				  

				  // Transmit images into ALP memory
				  if (ALP_OK != AlpSeqPut( nDevId, nSeqId[T], 0, PicNum, pImageData )) return ;
				  // Timing
				  if (ALP_OK != AlpSeqTiming( nDevId, nSeqId[T], ALP_DEFAULT, nPictureTime, ALP_DEFAULT, ALP_DEFAULT, ALP_DEFAULT ) ) return ;
				  // Start sequence				  
				  if (ALP_OK != AlpProjStartCont( nDevId, nSeqId[T] ));

					free(pImageData);
					serialPort1->DiscardInBuffer();

					sent = true;

					//timer->Enabled = false;
					str = "\0";
				  }
				  ///if  "s"

				  label_PictureTime->Text = nPictureTime.ToString("000.00");
		 }//timer
private: System::Void button_Move_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Btn=true;
		 }
private: System::Void button_Jump_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 Btn=false;
		 }
private: System::Void pictureBox1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) 
		 {///////////// 300 x 384 ////////////////
			 this->Label_XY->Text = "Coordinates X: " +e->X +" Y: " + e->Y  ;
			 if (2*e->X > squareSize/2+3*squareWidth && 2*e->X < nowXSize-(squareSize/2+3*squareWidth) &&
				 2*e->Y > squareSize/2+3*squareWidth && 2*e->Y < nowYSize-(squareSize/2+3*squareWidth))
			 {
				 X= 2*e->X;
				 Y= 2*e->Y;
			 }
		 }

private: System::Void trackBar1_Scroll(System::Object^  sender, System::EventArgs^  e) 
		 {
			 label_PictureTime->Text = (trackBar1->Value).ToString("000.00");

			 nPictureTime = trackBar1->Value;
		 }
private: System::Void serialPort1_DataReceived(System::Object^  sender, System::IO::Ports::SerialDataReceivedEventArgs^  e) 
		 {
			 str = serialPort1->ReadLine();
			 serialPort1->DiscardInBuffer();
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 nPictureTime+=0.1;
		 }
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 nPictureTime-=0.1;
		 }
};//Don't
}// Touch

