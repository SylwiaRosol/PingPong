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

        if(ball->Top-5 <= tlo->Top) y = -y;
        if(ball->Top + ball->Height + 5 >= tlo->Height) y = -y;

        if(ball->Left <= paddle1->Left - paddle1->Width) {
         TimerBall->Enabled = false;
         ball->Visible = false;
        }

        if(ball->Left >= paddle2->Left + paddle2->Width) {
         TimerBall->Enabled = false;
         ball->Visible = false;
        }


}
//---------------------------------------------------------------------------
void __fastcall TForm1::Paddle2DownTimer(TObject *Sender)
{
        paddle2->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Paddle2UpTimer(TObject *Sender)
{
        paddle2->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_UP) Paddle2Up->Enabled = true;
        if(Key == VK_DOWN) Paddle2Down->Enabled = true;

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if(Key == VK_UP) Paddle2Up->Enabled = false;
        if(Key == VK_DOWN) Paddle2Down->Enabled = false;
        
}
//---------------------------------------------------------------------------

