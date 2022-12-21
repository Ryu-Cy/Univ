import sys

from PyQt5.QtGui import QTextCursor
from PyQt5.QtWidgets import *
from PyQt5 import uic
from PyQt5 import QtCore

form_class = uic.loadUiType(".\\Notepad.ui")[0]

class FindWindow(QDialog):
    def __init__(self, parent):
        super(FindWindow, self).__init__(parent)
        uic.loadUi(".\\Find.ui", self)
        self.show()

        self.parent = parent
        self.cursor = parent.plainTextEdit.textCursor()
        self.pe = parent.plainTextEdit

        self.pushButtonFindNext.clicked.connect(self.findNext)
        self.pushButtonCancle.clicked.connect(self.close)
        self.radioButtonDown.clicked.connect(self.updownButton)
        self.radioButtonUp.clicked.connect(self.updownButton)
        self.upDown = "Down"

    def keyReleaseEvent(self, event):
        if self.lineEdit.text():
            self.pushButtonFindNext.setEnabled(True)
        else:
            self.pushButtonFindNext.setEnabled(False)

    def findNext(self):
        pattern = self.lineEdit.text()
        text = self.pe.toPlainText()

        reg = QtCore.QRegExp(pattern)

        self.cursor = self.parent.plainTextEdit.textCursor()

        if self.checkBoxCaseSensitive.isChecked():
            cs = QtCore.Qt.CaseSensitive
        else:
            cs = QtCore.Qt.CaseInsensitive

        reg.setCaseSensitivity(cs)
        pos = self.cursor.position()

        if self.upDown == "Down":
            index = reg.indexIn(text, pos)
        else:
            pos -= len(pattern) + 1
            index = reg.lastIndexIn(text, pos)

        if index != -1 and pos > -1:
            self.setCursor(index, len(pattern)+index)
        else:
            self.notFound(pattern)

    def setCursor(self, start, end):
        #print(self.cursor.selectionStart(), self.cursor.selectionEnd())

        self.cursor.setPosition(start)
        self.cursor.movePosition(QTextCursor.Right, QTextCursor.KeepAnchor, end-start)
        self.pe.setTextCursor(self.cursor)

    def notFound(self, pattern):
        msgBox = QMessageBox()
        msgBox.setWindowTitle('Error')
        msgBox.setIcon(QMessageBox.Information)
        msgBox.setText("{}을 찾을 수 없습니다.".format(pattern))
        msgBox.addButton('확인', QMessageBox.YesRole)  # 0
        ret = msgBox.exec_()

    def updownButton(self):
        if self.radioButtonUp.isChecked():
            self.upDown = "Up"
            print('up')
        elif self.radioButtonDown.isChecked():
            self.upDown = "Down"
            print('down')



class WindowClass(QMainWindow, form_class):
    def __init__(self):
        super().__init__()
        self.setupUi(self)

        self.actionOpen.triggered.connect(self.openFunction)
        self.actionSave.triggered.connect(self.saveFunction)
        self.actionSaveAs.triggered.connect(self.saveAsFunction)
        self.actionClose.triggered.connect(self.close)
        self.actionUndo.triggered.connect(self.undoFunction)
        self.actionCut.triggered.connect(self.cutFunction)
        self.actionCopy.triggered.connect(self.copyFunction)
        self.actionPaste.triggered.connect(self.pasteFunction)
        self.actionFind.triggered.connect(self.findFunction)

        self.opened = False
        self.opened_file_path = '제목 없음'

    def isChanged(self):
        if not self.opened:
            if self.plainTextEdit.toPlainText().strip():
                return True
            return False

        cur_data = self.plainTextEdit.toPlainText()
        with open(self.opened_file_path, encoding='UTF8') as f:
            file_data = f.read()

        if cur_data == file_data:
            return False
        else:
            return True

    def closeEvent(self, event):
        if self.isChanged():
            ret = self.changed_data()

            if ret == 2:
                event.ignore()

    def changed_data(self):
        msgBox = QMessageBox()
        msgBox.setText("변경 사항을 {}에 저장하시겠습니까?".format(self.opened_file_path))
        msgBox.addButton('저장', QMessageBox.YesRole) #0
        msgBox.addButton('저장 안 함', QMessageBox.NoRole) #1
        msgBox.addButton('취소', QMessageBox.RejectRole) #2
        ret = msgBox.exec_()

        if ret == 0:
            self.saveFunction()
        else:
            return ret

    def open_file(self, fname):
        with open(fname, 'r', encoding='UTF8') as f:
            data = f.read()

        self.plainTextEdit.setPlainText(data)
        self.opened = True
        self.opened_file_path = fname

    def save_file(self, fname):
        data = self.plainTextEdit.toPlainText()

        with open(fname, 'w', encoding='UTF8') as f:
            data = f.write(data)

        self.opened = True
        self.opened_file_path = fname

    def openFunction(self):
        if self.isChanged():
            ret = self.changed_data()

        fname = QFileDialog.getOpenFileName(self)
        if fname[0]:
            self.open_file(fname[0])

    def saveFunction(self):
        if self.opened:
            self.save_file(self.opened_file_path)
        else:
            fname = QFileDialog.getSaveFileName(self)
            if fname[0]:
                self.save_file(fname[0])

    def saveAsFunction(self):
        fname = QFileDialog.getSaveFileName(self)
        if fname[0]:
            self.save_file(fname[0])

    def undoFunction(self):
        self.plainTextEdit.undo()

    def cutFunction(self):
        self.plainTextEdit.cut()

    def copyFunction(self):
        self.plainTextEdit.copy()

    def pasteFunction(self):
        self.plainTextEdit.paste()

    def findFunction(self):
        FindWindow(self)


app = QApplication(sys.argv)
mainWindow = WindowClass()
mainWindow.show()
app.exec_()