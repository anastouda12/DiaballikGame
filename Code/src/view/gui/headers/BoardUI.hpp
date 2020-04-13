#ifndef BOARDUI_HPP
#define BOARDUI_HPP

#include <QGridLayout>
#include <QLabel>
#include <QWidget>

class SquareUI : public QWidget
{
    QLabel * label;

  public:
    SquareUI() : QWidget()
    {
        QPalette palette(this->palette());
        palette.setColor(backgroundRole(), Qt::red);
        setPalette(palette);

        label = new QLabel("1", this);
    }
};

class BoardUI : public QGridLayout
{
  public:
    BoardUI() : QGridLayout{}
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                this->addWidget(new SquareUI(), i, j);
            }
        }
    }
};

#endif // BOARDUI_HPP
