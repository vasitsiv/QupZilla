/* ============================================================
* QupZilla - WebKit based browser
* Copyright (C) 2010-2012  David Rosca <nowrep@gmail.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
* ============================================================ */
#ifndef SEARCHTOOLBAR_H
#define SEARCHTOOLBAR_H

#include <QWebPage>

#include "qz_namespace.h"
#include "animatedwidget.h"

namespace Ui
{
class SearchToolbar;
}

class QLineEdit;

class QupZilla;
class LineEdit;

class QT_QUPZILLA_EXPORT SearchToolBar : public AnimatedWidget
{
    Q_OBJECT
public:
    explicit SearchToolBar(QupZilla* mainClass, QWidget* parent = 0);
    ~SearchToolBar();

    void focusSearchLine();
    bool eventFilter(QObject* obj, QEvent* event);

signals:

public slots:
    void searchText(const QString &text);
    void updateFindFlags();
    void highlightChanged();
    void caseSensitivityChanged();

    void findNext();
    void findPrevious();

    void hide();

private:
    Ui::SearchToolbar* ui;
    QupZilla* p_QupZilla;

    QWebPage::FindFlags m_findFlags;
};

#endif // SEARCHTOOLBAR_H
