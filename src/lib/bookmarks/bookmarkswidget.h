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
#ifndef BOOKMARKSWIDGET_H
#define BOOKMARKSWIDGET_H

#include <QUrl>
#include <QMenu>

#include "qz_namespace.h"

namespace Ui
{
class BookmarksWidget;
}

class WebView;
class SpeedDial;
class BookmarksModel;
class QupZilla;

class QT_QUPZILLA_EXPORT BookmarksWidget : public QMenu
{
    Q_OBJECT
public:
    explicit BookmarksWidget(QupZilla* mainClass, WebView* view, QWidget* parent = 0);
    ~BookmarksWidget();
    void showAt(QWidget* _parent);

signals:
    void bookmarkDeleted();

private slots:
    void on_saveRemove_clicked(bool);
    void bookmarkEdited();

    void toggleSpeedDial();

private:
    void loadBookmark();

    Ui::BookmarksWidget* ui;
    QupZilla* p_QupZilla;
    QUrl m_url;
    int m_bookmarkId;

    WebView* m_view;
    BookmarksModel* m_bookmarksModel;
    SpeedDial* m_speedDial;
    bool m_edited;
};

#endif // BOOKMARKSWIDGET_H
