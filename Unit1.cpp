//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x=-8;
int y=-8;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
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
        } else if (ball->Top > paddle1->Top - ball->Height/2 &&
                    ball->Top < paddle1->Top + paddle1->Height &&
                    ball->Left <= paddle1->Left + paddle1->Width )
                {
                     x = -x;
                }

        if(ball->Left >= paddle2->Left + paddle2->Width) {
         TimerBall->Enabled = false;
         ball->Visible = false;
        }  else if (ball->Top > paddle2->Top - ball->Height/2 &&
                    ball->Top < paddle2->Top + paddle2->Height &&
                    ball->Left + ball->Width >= paddle2->Left)
                {
                     x = -x;
                }



}
//---------------------------------------------------------------------------

void __fastcall TForm1::Paddle1UpTimer(TObject *Sender)
{
        if( paddle1->Top > 10) paddle1->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Paddle1DownTimer(TObject *Sender)
{
        if(paddle1->Top + paddle1->Height < background->Height -10)
         paddle1->Top -=10;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Paddle2DownTimer(TObject *Sender)
{
       if (paddle2->Top + paddle2->Height < background->Height -10) paddle2->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Paddle2UpTimer(TObject *Sender)
{
          if( paddle2->Top > 10) paddle2->Top -= 10;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_UP) Paddle2Up->Enabled = true;
        if(Key == VK_DOWN) Paddle2Down->Enabled = true;
        //if(Key == VK_A) Paddle1Up->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_UP) Paddle2Up->Enabled = false;
        if(Key == VK_DOWN) Paddle2Down->Enabled = false;
        //if(Key == VK_A) Paddle1Up->Enabled = false;
}
//---------------------------------------------------------------------------

