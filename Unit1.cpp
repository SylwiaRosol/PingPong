//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x=-10;
int y=-10;
int pointLeft=0, pointRight=0;
int hit=0;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
AnsiString welcome= "Witaj w grze PingPong.";
AnsiString instruction = "Lewy gracz steruje wciskaj¹c klawicze A oraz Z.";
AnsiString instruction2 = "Prawy gracz steruje wciskaj¹c strza³ki do góry i w dó³.";
AnsiString news = "By gra by³a ciekawsza: ";
AnsiString news2 = "Im d³u¿ej odbijasz pi³eczkê, tym szybciej siê ona porusza";
AnsiString news3 ="Je¿eli odbijesz pi³eczkê srodkiem paletki, wtedy pi³eczka przyspieszy";
AnsiString haveFun = "Mi³ej zabawy!";

ShowMessage(welcome + sLineBreak + sLineBreak + instruction + sLineBreak +
instruction2 + sLineBreak + sLineBreak+ news + sLineBreak + news2 + sLineBreak + news3 +
sLineBreak + sLineBreak + haveFun);
}

//---------------------------------------------------------------------------

void __fastcall TForm1::TimerBallTimer(TObject *Sender)
{
        ball->Left+=x;
        ball->Top+=y;

        if(ball->Top-5 <= background->Top) y = -y;
        if(ball->Top + ball->Height + 5 >= background->Height) y = -y;

        if(ball->Left < paddle1->Left) {
         TimerBall->Enabled = false;
         ball->Visible = false;
         PointForTheRight->Visible = true;
         pointRight += 1;
         points->Caption = IntToStr(pointLeft) + " : " + IntToStr(pointRight);
         points->Visible = true;
         hits->Caption = " Ilosc odbic: " + IntToStr(hit);
         hits->Visible = true;
         nextRound->Visible = true;
         newGame->Visible = true;

        } else if ( ball->Top + ball->Height/2 == paddle1->Top + paddle1->Height/2
                && ball->Left <= paddle1->Left + paddle1->Width) {
                if(x < 0) {
                        x = -x;
                        x += 4;
                        }
        } else if (ball->Top > paddle1->Top - ball->Height/2 &&
                    ball->Top < paddle1->Top + paddle1->Height &&
                    ball->Left <= paddle1->Left + paddle1->Width )
        {
                if(x<0) {
                        x = -x;
                        hit +=1;
                        x += 1;
                        }
        }


        if(ball->Left >= paddle2->Left + paddle2->Width) {
         TimerBall->Enabled = false;
         ball->Visible = false;
         PointForTheLeft->Visible = true;
         pointLeft +=1;
         points->Caption = IntToStr(pointLeft) + " : " + IntToStr(pointRight);
         points->Visible = true;
         hits->Caption = " Ilosc odbic: " + IntToStr(hit);
         hits->Visible = true;
         nextRound->Visible = true;
         newGame->Visible = true;

        } else if ( ball->Top + ball->Height/2 == paddle2->Top + paddle2->Height/2
                && ball->Left + ball->Width >= paddle2->Left){
                if( x > 0) {
                        x = -x;
                        x -= 4;
                }
         } else if (ball->Top > paddle2->Top - ball->Height/2 &&
                    ball->Top < paddle2->Top + paddle2->Height &&
                    ball->Left + ball->Width >= paddle2->Left)
        {
        if(x > 0) {
                x = -x;
                x -= 1;
                hit +=1;
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Paddle1UpTimer(TObject *Sender)
{
        if( paddle1->Top > 10) paddle1->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Paddle1DownTimer(TObject *Sender)
{
        if(paddle1->Top + paddle1->Height < background->Height -10)
         paddle1->Top +=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Paddle2UpTimer(TObject *Sender)
{
          if( paddle2->Top > 10) paddle2->Top -= 10;

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Paddle2DownTimer(TObject *Sender)
{
       if (paddle2->Top + paddle2->Height < background->Height -10) paddle2->Top += 10;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_UP) Paddle2Up->Enabled = true;
        if(Key == VK_DOWN) Paddle2Down->Enabled = true;
        if(Key == 0x41) Paddle1Up->Enabled = true;
        if(Key == 0x5A) Paddle1Down->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_UP) Paddle2Up->Enabled = false;
        if(Key == VK_DOWN) Paddle2Down->Enabled = false;
        if(Key == 0x41) Paddle1Up->Enabled = false;
        if(Key == 0x5A) Paddle1Down->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::newGameClick(TObject *Sender)
{
        newGame->Visible = false;
        title->Visible = false;
        points->Visible = false;
        PointForTheLeft->Visible = false;
        PointForTheRight->Visible = false;
        hits->Visible = false;
        nextRound->Visible = false;
        hit=0;
        pointLeft=0; pointRight=0;
        ball->Left = 400;
        ball->Top = 200;
        ball->Visible = true;
        x=4; y=4;
        TimerBall->Enabled = true;

}
//---------------------------------------------------------------------------




void __fastcall TForm1::nextRoundClick(TObject *Sender)
{
        title->Visible = false;
        points->Visible = false;
        PointForTheLeft->Visible = false;
        PointForTheRight->Visible = false;
        hits->Visible = false;
        nextRound->Visible = false;
        newGame->Visible = false;
        ball->Left = 400;
        ball->Top = 200;
        ball->Visible = true;
        x=4; y=-4; hit=0;
        TimerBall->Enabled = true;

}
//---------------------------------------------------------------------------


