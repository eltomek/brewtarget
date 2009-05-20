/*
 * MaltinessWidget.h is part of Brewtarget, and is Copyright Philip G. Lee
 * (rocketman768@gmail.com), 2009.
 *
 * Brewtarget is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * Brewtarget is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _MALTINESSWIDGET_H
#define	_MALTINESSWIDGET_H

class MaltinessWidget;

#include <QWidget>
#include <QColor>
#include <QPaintEvent>
#include <QLabel>
#include <QPalette>
#include "observable.h"
#include "recipe.h"

enum{ CLOYING, EXTRAMALTY, SLIGHTLYMALTY, BALANCED, SLIGHTLYHOPPY, EXTRAHOPPY, HARSH };

class MaltinessWidget : public QWidget, public Observer
{
   Q_OBJECT

public:
   MaltinessWidget();
   MaltinessWidget(Recipe* recipe);
   void observeRecipe(Recipe* recipe);

   virtual void notify(Observable *notifier, QVariant info = QVariant()); // This will get called by observed whenever it changes.

protected:
   virtual void paintEvent(QPaintEvent *);

private:

   void setup();
   QColor bgColor();
   QString fgText();
   int region();

   QPalette palette;
   QLabel* label;
   Recipe* recObs;
};

#endif	/* _MALTINESSWIDGET_H */
