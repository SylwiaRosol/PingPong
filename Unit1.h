//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *background;
        TImage *ball;
        TTimer *TimerBall;
        TImage *paddle1;
        TImage *paddle2;
        TTimer *Paddle2Up;
        TTimer *Paddle2Down;
        TTimer *Paddle1Up;
        TTimer *Paddle1Down;
        TLabel *title;
        TButton *newGame;
        TLabel *PointForTheRight;
        TLabel *PointForTheLeft;
        TLabel *points;
        TButton *nextRound;
        TLabel *hits;
        void __fastcall TimerBallTimer(TObject *Sender);
        void __fastcall Paddle2DownTimer(TObject *Sender);
        void __fastcall Paddle2UpTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Paddle1UpTimer(TObject *Sender);
        void __fastcall Paddle1DownTimer(TObject *Sender);
        void __fastcall newGameClick(TObject *Sender);
        void __fastcall nextRoundClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
