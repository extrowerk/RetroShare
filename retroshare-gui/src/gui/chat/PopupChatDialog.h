/****************************************************************
 *  RetroShare is distributed under the following license:
 *
 *  Copyright (C) 2006, crypton
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, 
 *  Boston, MA  02110-1301, USA.
 ****************************************************************/


#ifndef _POPUPCHATDIALOG_H
#define _POPUPCHATDIALOG_H

#include "ui_PopupChatDialog.h"

class QAction;
class QTextEdit;
class QTextCharFormat;
class AttachFileItem;
class ChatInfo;

#include "ChatStyle.h"

class PopupChatDialog : public QMainWindow
{
  Q_OBJECT

public:
  static PopupChatDialog *getPrivateChat(std::string id, uint chatflags);
  static void cleanupChat();
  static void chatFriend(std::string id);
  static void updateAllAvatars();
  static void privateChatChanged(int list, int type);

  void updateChat();
  void updatePeerAvatar(const std::string&);

public slots:
  /** Overloaded QWidget.show */
  void show(); 

  void getfocus();
  void flash(); 
  void pasteLink() ;
  void contextMenu(QPoint) ;

  void smileyWidget();
  void addSmiley();

  void fileHashingFinished(AttachFileItem* file);

  void resetStatusBar() ;
  void updateStatusTyping() ;
  void updateStatusString(const QString& peer_id, const QString& statusString) ;
  void anchorClicked (const QUrl &);

  void updateStatus(const QString &peer_id, int status);

protected:
  /** Default constructor */
  PopupChatDialog(std::string id, const QString name, QWidget *parent = 0, Qt::WFlags flags = 0);
  /** Default destructor */
  ~PopupChatDialog();

  void closeEvent (QCloseEvent * event);
  void showEvent (QShowEvent * event);
  virtual void dragEnterEvent(QDragEnterEvent *event);
  virtual void dropEvent(QDropEvent *event);

  bool eventFilter(QObject *obj, QEvent *ev);

  void insertChatMsgs();
  void addChatMsg(std::string &id, uint sendTime, std::wstring &msg, bool offline);

  void updateAvatar();

  QPixmap picture;

private slots:
  void addExtraFile();
  void addExtraPicture();
  void showAvatarFrame(bool show);
  void on_closeInfoFrameButton_clicked();

  void setColor();
  void getFont();
  void setFont();
 
  void sendChat();

  void updatePeersCustomStateString(const QString& peer_id, const QString& status_string) ;
  void getAvatar();

  void on_actionClear_Chat_triggered();

  bool fileSave();
  bool fileSaveAs();
  void clearOfflineMessages();


private:

  void setCurrentFileName(const QString &fileName);

  void colorChanged(const QColor &c);
  void fontChanged(const QFont &font);
  void addAttachment(std::string,int flag);
  void processSettings(bool bLoad);

   void onPrivateChatChanged(int list, int type);

   QAction *actionTextBold;
   QAction *actionTextUnderline;
   QAction *actionTextItalic;
   QAction *pasteLinkAct ;

   std::string dialogId;
   QString dialogName;
   unsigned int lastChatTime;
   std::string  lastChatName;

   time_t last_status_send_time ;
   QColor mCurrentColor;
   QFont  mCurrentFont;

//   QStringList history;
   QString wholeChat;
   QString fileName; 

   bool m_bInsertOnVisible;
   ChatStyle style;

  /** Qt Designer generated object */
  Ui::PopupChatDialog ui;

};

#endif




