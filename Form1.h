#pragma once
#include "func.h"
#include "Du.h"
#include <fstream>
#include <math.h>
#include <string>
#include <cmath>
#include <msclr\marshal_cppstd.h>
#include <iostream>
#include <iomanip>
namespace Duorb {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;
	using namespace std;
	
	/// <summary>
	/// —водка дл€ Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected: 




	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::TextBox^  tBP;

	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  tBm;

	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  tBteta;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  tBu;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  tBOm;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  tBi;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  tBec;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  tBa;

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  tBw;

	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  tBud;

	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::TextBox^  tBdelta;

	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  tBt;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  tbDelta0F;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::TextBox^  tbAlfa0F;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::TextBox^  tbAlfaDotF;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::TextBox^  tbDeltaDotF;


	private:
		/// <summary>
		/// “ребуетс€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ќб€зательный метод дл€ поддержки конструктора - не измен€йте
		/// содержимое данного метода при помощи редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->tBt = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->tBdelta = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->tBw = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->tBud = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->tBP = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->tBm = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->tBteta = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tBu = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->tBOm = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tBi = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tBec = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tBa = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->tbDelta0F = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->tbAlfa0F = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->tbAlfaDotF = (gcnew System::Windows::Forms::TextBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->tbDeltaDotF = (gcnew System::Windows::Forms::TextBox());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label13);
			this->panel1->Controls->Add(this->tbDelta0F);
			this->panel1->Controls->Add(this->label14);
			this->panel1->Controls->Add(this->tbAlfa0F);
			this->panel1->Controls->Add(this->label12);
			this->panel1->Controls->Add(this->tBt);
			this->panel1->Controls->Add(this->label11);
			this->panel1->Controls->Add(this->tBdelta);
			this->panel1->Controls->Add(this->label10);
			this->panel1->Controls->Add(this->tBw);
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->tBud);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->tBP);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->tBm);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->tBteta);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->tBu);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->tBOm);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->tBi);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->tBec);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->tBa);
			this->panel1->Location = System::Drawing::Point(26, 22);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(397, 313);
			this->panel1->TabIndex = 0;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(263, 63);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(14, 20);
			this->label12->TabIndex = 23;
			this->label12->Text = L"t";
			// 
			// tBt
			// 
			this->tBt->Location = System::Drawing::Point(267, 86);
			this->tBt->Name = L"tBt";
			this->tBt->Size = System::Drawing::Size(121, 26);
			this->tBt->TabIndex = 22;
			this->tBt->Text = L"100";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(263, 9);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(138, 20);
			this->label11->TabIndex = 21;
			this->label11->Text = L"врем€ работы ду";
			// 
			// tBdelta
			// 
			this->tBdelta->Location = System::Drawing::Point(267, 32);
			this->tBdelta->Name = L"tBdelta";
			this->tBdelta->Size = System::Drawing::Size(121, 26);
			this->tBdelta->TabIndex = 20;
			this->tBdelta->Text = L"100";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(140, 236);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(20, 20);
			this->label10->TabIndex = 19;
			this->label10->Text = L"w";
			// 
			// tBw
			// 
			this->tBw->Location = System::Drawing::Point(140, 259);
			this->tBw->Name = L"tBw";
			this->tBw->Size = System::Drawing::Size(121, 26);
			this->tBw->TabIndex = 18;
			this->tBw->Text = L"324,680";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(136, 179);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(82, 20);
			this->label9->TabIndex = 17;
			this->label9->Text = L"удельна€";
			// 
			// tBud
			// 
			this->tBud->Location = System::Drawing::Point(140, 202);
			this->tBud->Name = L"tBud";
			this->tBud->Size = System::Drawing::Size(121, 26);
			this->tBud->TabIndex = 16;
			this->tBud->Text = L"333";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(136, 123);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(43, 20);
			this->label8->TabIndex = 15;
			this->label8->Text = L"т€га";
			// 
			// tBP
			// 
			this->tBP->Location = System::Drawing::Point(140, 146);
			this->tBP->Name = L"tBP";
			this->tBP->Size = System::Drawing::Size(121, 26);
			this->tBP->TabIndex = 14;
			this->tBP->Text = L"2000";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(136, 63);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(22, 20);
			this->label7->TabIndex = 13;
			this->label7->Text = L"m";
			// 
			// tBm
			// 
			this->tBm->Location = System::Drawing::Point(140, 86);
			this->tBm->Name = L"tBm";
			this->tBm->Size = System::Drawing::Size(121, 26);
			this->tBm->TabIndex = 12;
			this->tBm->Text = L"7000";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(136, 9);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(37, 20);
			this->label6->TabIndex = 11;
			this->label6->Text = L"teta";
			// 
			// tBteta
			// 
			this->tBteta->Location = System::Drawing::Point(140, 32);
			this->tBteta->Name = L"tBteta";
			this->tBteta->Size = System::Drawing::Size(121, 26);
			this->tBteta->TabIndex = 10;
			this->tBteta->Text = L"210,186";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(9, 236);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(18, 20);
			this->label5->TabIndex = 9;
			this->label5->Text = L"u";
			// 
			// tBu
			// 
			this->tBu->Location = System::Drawing::Point(13, 259);
			this->tBu->Name = L"tBu";
			this->tBu->Size = System::Drawing::Size(121, 26);
			this->tBu->TabIndex = 8;
			this->tBu->Text = L"324,680";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(9, 179);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(34, 20);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Om";
			// 
			// tBOm
			// 
			this->tBOm->Location = System::Drawing::Point(13, 202);
			this->tBOm->Name = L"tBOm";
			this->tBOm->Size = System::Drawing::Size(121, 26);
			this->tBOm->TabIndex = 6;
			this->tBOm->Text = L"75,751";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 124);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(12, 20);
			this->label3->TabIndex = 5;
			this->label3->Text = L"i";
			// 
			// tBi
			// 
			this->tBi->Location = System::Drawing::Point(13, 146);
			this->tBi->Name = L"tBi";
			this->tBi->Size = System::Drawing::Size(121, 26);
			this->tBi->TabIndex = 4;
			this->tBi->Text = L"98,013";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(18, 20);
			this->label2->TabIndex = 3;
			this->label2->Text = L"e";
			// 
			// tBec
			// 
			this->tBec->Location = System::Drawing::Point(13, 86);
			this->tBec->Name = L"tBec";
			this->tBec->Size = System::Drawing::Size(121, 26);
			this->tBec->TabIndex = 2;
			this->tBec->Text = L"0";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(18, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"a";
			// 
			// tBa
			// 
			this->tBa->Location = System::Drawing::Point(13, 32);
			this->tBa->Name = L"tBa";
			this->tBa->Size = System::Drawing::Size(121, 26);
			this->tBa->TabIndex = 0;
			this->tBa->Text = L"7032,012";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(429, 136);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(176, 67);
			this->button1->TabIndex = 1;
			this->button1->Text = L"ѕоехали";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(263, 177);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(81, 20);
			this->label13->TabIndex = 27;
			this->label13->Text = L"рыскание";
			// 
			// tbDelta0F
			// 
			this->tbDelta0F->Location = System::Drawing::Point(267, 200);
			this->tbDelta0F->Name = L"tbDelta0F";
			this->tbDelta0F->Size = System::Drawing::Size(121, 26);
			this->tbDelta0F->TabIndex = 26;
			this->tbDelta0F->Text = L"0";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(263, 123);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(63, 20);
			this->label14->TabIndex = 25;
			this->label14->Text = L"тангаж";
			// 
			// tbAlfa0F
			// 
			this->tbAlfa0F->Location = System::Drawing::Point(267, 146);
			this->tbAlfa0F->Name = L"tbAlfa0F";
			this->tbAlfa0F->Size = System::Drawing::Size(121, 26);
			this->tbAlfa0F->TabIndex = 24;
			this->tbAlfa0F->Text = L"90";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(3, 3);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(176, 20);
			this->label15->TabIndex = 29;
			this->label15->Text = L"склонени€ по тангажу";
			// 
			// tbAlfaDotF
			// 
			this->tbAlfaDotF->Location = System::Drawing::Point(3, 28);
			this->tbAlfaDotF->Name = L"tbAlfaDotF";
			this->tbAlfaDotF->Size = System::Drawing::Size(121, 26);
			this->tbAlfaDotF->TabIndex = 28;
			this->tbAlfaDotF->Text = L"0,06";
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label16);
			this->panel2->Controls->Add(this->tbDeltaDotF);
			this->panel2->Controls->Add(this->label15);
			this->panel2->Controls->Add(this->tbAlfaDotF);
			this->panel2->Location = System::Drawing::Point(429, 209);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(201, 126);
			this->panel2->TabIndex = 2;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(3, 62);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(190, 20);
			this->label16->TabIndex = 31;
			this->label16->Text = L"склонени€ по рысканию";
			// 
			// tbDeltaDotF
			// 
			this->tbDeltaDotF->Location = System::Drawing::Point(3, 85);
			this->tbDeltaDotF->Name = L"tbDeltaDotF";
			this->tbDeltaDotF->Size = System::Drawing::Size(121, 26);
			this->tbDeltaDotF->TabIndex = 30;
			this->tbDeltaDotF->Text = L"0";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(631, 359);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->panel1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	double ec, a, i, Om, u, w, teta;
	struct Vector3x1 X;
	struct Vector3x1 V;
	double r[8],P[3],F[3],f1[3],A[3][3];
	int count;
	double t = Convert::ToDouble(tBt->Text);
	double delta = Convert::ToDouble(tBdelta->Text);;
	double tk = t + delta;
	double udm = Convert::ToDouble(tBP->Text) / Convert::ToDouble(tBud->Text);
	double h = 0.1;
	double Alfa0F = Convert::ToDouble(tbAlfa0F->Text)*torad;
	double AlfaDotF = Convert::ToDouble(tbAlfaDotF->Text)*torad;
	double Delta0F = Convert::ToDouble(tbDelta0F->Text)*torad;
	double DeltaDotF = Convert::ToDouble(tbDeltaDotF->Text)*torad;
	double t0f,Alfa,Delta,dtp;
	double rper,rap,hper,hap;
	t0f = t;
	button1->Text = "считаем";
	ec = Convert::ToDouble(tBec->Text);
	i = Convert::ToDouble(tBi->Text) * torad;
	a = Convert::ToDouble(tBa->Text);
	Om = Convert::ToDouble(tBOm->Text) * torad;
	u = Convert::ToDouble(tBu->Text)* torad;
	if (ec == 0) {
			w = u;
		}
		else { w = Convert::ToDouble(tBw->Text) * torad; }
	teta =  getteta(u, w);//Convert::ToDouble(tBteta->Text) * torad;
	rper = getrper( a, ec);
	rap = getrap(a, ec);
	hper = gethper( rper);
	hap = gethap( rap);
	getGrKP(X, V, ec, a, i, Om, u, w, teta);
	r[0] = X.x;
	r[1] = X.y;
	r[2] = X.z;
	r[3] = V.x;
	r[4] = V.y;
	r[5] = V.z;
	r[6] = Convert::ToDouble(tBm->Text);
	r[7] = 0;
	P[0]=0;
	P[1]= Convert::ToDouble(tBP->Text)*g0/1e3;
	P[2]=0;
	ofstream fout1("du.txt");
	fout1 << "\n";
	fout1  << setw( 12 ) << setiosflags( ios::right ) << "t ";
	fout1  << setw( 12 ) << setiosflags( ios::right ) << "x ";
	fout1  << setw( 12 ) << setiosflags( ios::right ) << "y ";
	fout1  << setw( 12 ) << setiosflags( ios::right ) << "z ";
	fout1  << setw( 12 ) << setiosflags( ios::right ) << "Vx ";
	fout1  << setw( 12 ) << setiosflags( ios::right ) << "Vy ";
	fout1  << setw( 12 ) << setiosflags( ios::right ) << "Vz ";
	fout1  << setw( 12 ) << setiosflags( ios::right ) << "m";
	fout1  << setw( 12 ) << setiosflags( ios::right ) << "Vхар";
	fout1  << setw( 12 ) << setiosflags( ios::right ) << "alpha";
	fout1  << setw( 12 ) << setiosflags( ios::right ) << "delta"<<  endl;
	// начинаем интегрировать –к4 -> с заданным шагом
	fout1 << setw( 12 ) << setiosflags( ios::right ) << setprecision( 1 ) << fixed <<  t  ;
	for (count = 0; count < 3; count++){
		fout1 << setw( 12 ) << setiosflags( ios::right ) << setprecision( 3 ) << fixed <<  r[count]  ;
	}
	for (count = 3; count < 6; count++){
		fout1 << setw( 12 ) << setiosflags( ios::right ) << setprecision( 6 ) << fixed <<  r[count]  ;
	}
	fout1 << setw( 12 ) << setiosflags( ios::right )<< setprecision( 2 )  << fixed <<  r[6]  ;
	fout1 << setw( 12 ) << setiosflags( ios::right )<< setprecision( 6 )  << fixed <<  r[7]  ;
	fout1 << setw( 12 ) << setiosflags( ios::right )<< setprecision( 3 )  << fixed <<  Alfa0F* tograd  ;
	fout1 << setw( 12 ) << setiosflags( ios::right )<< setprecision( 3 )  << fixed <<  Delta0F* tograd ;
	fout1 <<  endl;
	gertransmatfstw (r, A);
	ofstream fout2("duorb.txt");
	fout2 << "\n";
	fout2  << setw( 12 ) << setiosflags( ios::right ) << "t ";
	fout2  << setw( 12 ) << setiosflags( ios::right ) << "a ";
	fout2  << setw( 12 ) << setiosflags( ios::right ) << "e ";
	fout2  << setw( 12 ) << setiosflags( ios::right ) << "i ";
	fout2  << setw( 12 ) << setiosflags( ios::right ) << "Om ";
	fout2  << setw( 12 ) << setiosflags( ios::right ) << "u ";
	fout2  << setw( 12 ) << setiosflags( ios::right ) << "w ";
	fout2  << setw( 12 ) << setiosflags( ios::right ) << "teta";
	fout2  << setw( 12 ) << setiosflags( ios::right ) << "hper";
	fout2  << setw( 12 ) << setiosflags( ios::right ) << "hap";
	fout2  << setw( 12 ) << setiosflags( ios::right ) << "s";
	fout2  << setw( 12 ) << setiosflags( ios::right ) << "t";
	fout2  << setw( 12 ) << setiosflags( ios::right ) << "w"<<  endl;
	t += h;
	gertransfermatrixfromstw (Om,u,i, A);
	int T = 1;
	double csd;
	if (h < 0){ T = -1;}
	while (T*t < T*tk){
		//X.x = r[0]; X.y = r[1]; X.z = r[2];
		//V.x = r[3]; V.y = r[4]; V.z = r[5];
		//getorbparam(X, V, ec, a, i, Om, u, w, teta);
		//gertransfermatrixfromstw (Om,u,i, A);
		//gertransmatfstw (r, A);
		dtp=t-t0f;
		Alfa=Alfa0F+AlfaDotF*dtp;
		Delta=Delta0F+DeltaDotF*dtp;
		csd = cos(Delta);
		f1[0]=P[1]*cos(Alfa)*csd;
		f1[1]=P[1]*sin(Alfa)*csd;
		f1[2]=(-1)*P[1]*sin(Delta);
		getGRfStw(f1, A, F);
		RK4OneStepDu (RightPartDu, t,r,h,F, udm );
		fout1 << setw( 12 ) << setiosflags( ios::right ) << setprecision( 1 ) << fixed <<  t  ;
		for (count = 0; count < 3; count++){
			fout1 << setw( 12 ) << setiosflags( ios::right ) << setprecision( 3 ) << fixed <<  r[count]  ;

		}
		for (count = 3; count < 6; count++){
			fout1 << setw( 12 ) << setiosflags( ios::right ) << setprecision( 6 ) << fixed <<  r[count]  ;
		}
		fout1 << setw( 12 ) << setiosflags( ios::right )<< setprecision( 2 )  << fixed <<  r[6]  ;
		fout1 << setw( 12 ) << setiosflags( ios::right )<< setprecision( 6 )  << fixed <<  r[7]  ;
		fout1 << setw( 12 ) << setiosflags( ios::right )<< setprecision( 3 )  << fixed <<  Alfa* tograd  ;
		fout1 << setw( 12 ) << setiosflags( ios::right )<< setprecision( 3 )  << fixed <<  Delta* tograd  ;
		fout1 <<  endl;
		X.x = r[0]; X.y = r[1]; X.z = r[2];
		V.x = r[3]; V.y = r[4]; V.z = r[5];
		getorbparam(X, V, ec, a, i, Om, u, w, teta);
		rper = getrper( a, ec);
		rap = getrap(a, ec);
		hper = gethper( rper);
		hap = gethap( rap);
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << t ;
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << a;
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 6 ) << fixed << ec;
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << i* tograd ;
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << Om* tograd;
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << u* tograd;
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << w* tograd;
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << teta* tograd;
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << hper;
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << hap;
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << F[0]/P[1];
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << F[1]/P[1];
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << F[2]/P[1] <<  endl;
		t += h;
	}
	if (t > tk){
		t = t - h;
		h = tk - t;
		//X.x = r[0]; X.y = r[1]; X.z = r[2];
		//V.x = r[3]; V.y = r[4]; V.z = r[5];
		//getorbparam(X, V, ec, a, i, Om, u, w, teta);
		//gertransfermatrixfromstw (Om,u,i, A);
		//gertransmatfstw (r, A);
		dtp=t-t0f;
		Alfa=Alfa0F+AlfaDotF*dtp;
		Delta=Delta0F+DeltaDotF*dtp;
		csd = cos(Delta);
		f1[0]=P[1]*cos(Alfa)*csd;
		f1[1]=P[1]*sin(Alfa)*csd;
		f1[2]=(-1)*P[1]*sin(Delta);
		getGRfStw( f1, A, F);
		RK4OneStepDu (RightPartDu, t,r,h,F, udm );
		fout1 << setw( 12 ) << setiosflags( ios::right ) << setprecision( 1 ) << fixed <<  t  ;
		for (count = 0; count < 3; count++){
			fout1 << setw( 12 ) << setiosflags( ios::right ) << setprecision( 3 ) << fixed <<  r[count]  ;
		}
		for (count = 3; count < 6; count++){
			fout1 << setw( 12 ) << setiosflags( ios::right ) << setprecision( 6 ) << fixed <<  r[count]  ;
		}
		fout1 << setw( 12 ) << setiosflags( ios::right )<< setprecision( 2 )  << fixed <<  r[6]  ;
		fout1 << setw( 12 ) << setiosflags( ios::right )<< setprecision( 6 )  << fixed <<  r[7]  ;
		fout1 << setw( 12 ) << setiosflags( ios::right )<< setprecision( 3 )  << fixed <<  Alfa* tograd  ;
		fout1 << setw( 12 ) << setiosflags( ios::right )<< setprecision( 3 )  << fixed <<  Delta* tograd  ;
		fout1 <<  endl;
		X.x = r[0]; X.y = r[1]; X.z = r[2];
		V.x = r[3]; V.y = r[4]; V.z = r[5];
		getorbparam(X, V, ec, a, i, Om, u, w, teta);
		rper = getrper( a, ec);
		rap = getrap(a, ec);
		hper = gethper( rper);
		hap = gethap( rap);
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << t ;
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << a;
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 6 ) << fixed << ec;
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << i* tograd;
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << Om* tograd;
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << u* tograd;
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << w* tograd;
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << teta* tograd;
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << hper;
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << hap;
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << f1[0]/P[1];
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << f1[1]/P[1];
		fout2  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << f1[2]/P[1] <<  endl;
		t += h; 
	}
	fout1.close();
	fout2.close();
	button1->Text = "готово";
	ec = 0;
	a = Re+200;
	i = 40;
	Om = 75.750;
	w=0;
	t=0;
	tk=200;
	h = 0.1;
	teta=0;
	getGrKP(X, V, ec, a, i, Om, w, w, teta);
	r[0] = X.x;
	r[1] = X.y;
	r[2] = X.z;
	r[3] = V.x;
	r[4] = V.y;
	r[5] = V.z;
	r[6] = Convert::ToDouble(tBm->Text);
	r[7] = 0;
	rper = getrper( a, ec);
	rap = getrap(a, ec);
	hper = gethper( rper);
	hap = gethap( rap);
	ofstream fout3("dukr.txt");
	fout3 << "\n";
	fout3  << setw( 12 ) << setiosflags( ios::right ) << "t ";
	fout3  << setw( 12 ) << setiosflags( ios::right ) << "hper ";
	fout3  << setw( 12 ) << setiosflags( ios::right ) << "hap "<<  endl;
	fout3  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 2 ) << fixed << t;
	fout3  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << hper;
	fout3  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << hap <<  endl;
	t += h;
	if (h < 0){ T = -1;}
	while (T*t < T*tk){
		//X.x = r[0]; X.y = r[1]; X.z = r[2];
		//V.x = r[3]; V.y = r[4]; V.z = r[5];
		//getorbparam(X, V, ec, a, i, Om, u, w, teta);
		//gertransfermatrixfromstw (Om,u,i, A);
		gertransmatfstw (r, A);
		getGRfStw(P, A, F);
		RK4OneStepDu (RightPartDu, t,r,h,F, udm );
		X.x = r[0]; X.y = r[1]; X.z = r[2];
		V.x = r[3]; V.y = r[4]; V.z = r[5];
		getorbparam(X, V, ec, a, i, Om, u, w, teta);
		rper = getrper( a, ec);
		rap = getrap(a, ec);
		hper = gethper( rper);
		hap = gethap( rap);
		fout3  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 2 ) << fixed << t;
		fout3  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << hper;
		fout3  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << hap <<  endl;
		t += h;
	}
	if (t > tk){
		t = t - h;
		h = tk - t;
		//X.x = r[0]; X.y = r[1]; X.z = r[2];
		//V.x = r[3]; V.y = r[4]; V.z = r[5];
		//getorbparam(X, V, ec, a, i, Om, u, w, teta);
		//gertransfermatrixfromstw (Om,u,i, A);
		gertransmatfstw (r, A);
		getGRfStw( P, A, F);
		RK4OneStepDu (RightPartDu, t,r,h,F, udm );
		X.x = r[0]; X.y = r[1]; X.z = r[2];
		V.x = r[3]; V.y = r[4]; V.z = r[5];
		getorbparam(X, V, ec, a, i, Om, u, w, teta);
		rper = getrper( a, ec);
		rap = getrap(a, ec);
		hper = gethper( rper);
		hap = gethap( rap);
		fout3  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 2 ) << fixed << t;
		fout3  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << hper;
		fout3  << setw( 12 ) << setiosflags( ios::right )  << setprecision( 3 ) << fixed << hap <<  endl;
		t += h; 
	}
	fout3.close();
	button1->Text = "";
		 }
};
}
