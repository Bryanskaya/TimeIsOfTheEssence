# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'main_window.ui'
#
# Created by: PyQt5 UI code generator 5.4.1
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_MainWindow(object):
    def setupUi(self, MainWindow):
        MainWindow.setObjectName("MainWindow")
        MainWindow.resize(800, 664)
        self.centralwidget = QtWidgets.QWidget(MainWindow)
        self.centralwidget.setObjectName("centralwidget")
        self.label = QtWidgets.QLabel(self.centralwidget)
        self.label.setGeometry(QtCore.QRect(270, 10, 281, 16))
        font = QtGui.QFont()
        font.setPointSize(11)
        font.setBold(True)
        font.setWeight(75)
        self.label.setFont(font)
        self.label.setObjectName("label")
        self.Funcs = QtWidgets.QComboBox(self.centralwidget)
        self.Funcs.setGeometry(QtCore.QRect(10, 60, 181, 22))
        font = QtGui.QFont()
        font.setBold(True)
        font.setWeight(75)
        self.Funcs.setFont(font)
        self.Funcs.setObjectName("Funcs")
        self.Funcs.addItem("")
        self.Funcs.addItem("")
        self.Funcs.addItem("")
        self.Funcs.addItem("")
        self.Funcs.addItem("")
        self.Funcs.addItem("")
        self.label_2 = QtWidgets.QLabel(self.centralwidget)
        self.label_2.setGeometry(QtCore.QRect(10, 30, 101, 16))
        font = QtGui.QFont()
        font.setPointSize(10)
        font.setBold(True)
        font.setWeight(75)
        self.label_2.setFont(font)
        self.label_2.setObjectName("label_2")
        self.label_3 = QtWidgets.QLabel(self.centralwidget)
        self.label_3.setGeometry(QtCore.QRect(10, 90, 71, 16))
        font = QtGui.QFont()
        font.setPointSize(10)
        font.setBold(True)
        font.setWeight(75)
        self.label_3.setFont(font)
        self.label_3.setObjectName("label_3")
        self.line = QtWidgets.QFrame(self.centralwidget)
        self.line.setGeometry(QtCore.QRect(80, 90, 111, 20))
        self.line.setFrameShape(QtWidgets.QFrame.HLine)
        self.line.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line.setObjectName("line")
        self.line_2 = QtWidgets.QFrame(self.centralwidget)
        self.line_2.setGeometry(QtCore.QRect(0, 110, 20, 81))
        self.line_2.setFrameShape(QtWidgets.QFrame.VLine)
        self.line_2.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line_2.setObjectName("line_2")
        self.label_4 = QtWidgets.QLabel(self.centralwidget)
        self.label_4.setGeometry(QtCore.QRect(20, 120, 21, 16))
        font = QtGui.QFont()
        font.setPointSize(11)
        font.setBold(True)
        font.setWeight(75)
        self.label_4.setFont(font)
        self.label_4.setObjectName("label_4")
        self.XStart = QtWidgets.QLineEdit(self.centralwidget)
        self.XStart.setGeometry(QtCore.QRect(40, 120, 41, 20))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.XStart.setFont(font)
        self.XStart.setObjectName("XStart")
        self.XEnd = QtWidgets.QLineEdit(self.centralwidget)
        self.XEnd.setGeometry(QtCore.QRect(90, 120, 41, 20))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.XEnd.setFont(font)
        self.XEnd.setObjectName("XEnd")
        self.ZStart = QtWidgets.QLineEdit(self.centralwidget)
        self.ZStart.setGeometry(QtCore.QRect(40, 150, 41, 20))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.ZStart.setFont(font)
        self.ZStart.setObjectName("ZStart")
        self.ZEnd = QtWidgets.QLineEdit(self.centralwidget)
        self.ZEnd.setGeometry(QtCore.QRect(90, 150, 41, 20))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.ZEnd.setFont(font)
        self.ZEnd.setObjectName("ZEnd")
        self.label_6 = QtWidgets.QLabel(self.centralwidget)
        self.label_6.setGeometry(QtCore.QRect(20, 150, 21, 21))
        font = QtGui.QFont()
        font.setPointSize(11)
        font.setBold(True)
        font.setWeight(75)
        self.label_6.setFont(font)
        self.label_6.setObjectName("label_6")
        self.line_3 = QtWidgets.QFrame(self.centralwidget)
        self.line_3.setGeometry(QtCore.QRect(10, 180, 181, 20))
        self.line_3.setFrameShape(QtWidgets.QFrame.HLine)
        self.line_3.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line_3.setObjectName("line_3")
        self.label_7 = QtWidgets.QLabel(self.centralwidget)
        self.label_7.setGeometry(QtCore.QRect(10, 200, 31, 16))
        font = QtGui.QFont()
        font.setPointSize(10)
        font.setBold(True)
        font.setWeight(75)
        self.label_7.setFont(font)
        self.label_7.setObjectName("label_7")
        self.label_8 = QtWidgets.QLabel(self.centralwidget)
        self.label_8.setGeometry(QtCore.QRect(20, 230, 21, 16))
        font = QtGui.QFont()
        font.setPointSize(11)
        font.setBold(True)
        font.setWeight(75)
        self.label_8.setFont(font)
        self.label_8.setObjectName("label_8")
        self.label_9 = QtWidgets.QLabel(self.centralwidget)
        self.label_9.setGeometry(QtCore.QRect(20, 270, 21, 16))
        font = QtGui.QFont()
        font.setPointSize(11)
        font.setBold(True)
        font.setWeight(75)
        self.label_9.setFont(font)
        self.label_9.setObjectName("label_9")
        self.DX = QtWidgets.QLineEdit(self.centralwidget)
        self.DX.setGeometry(QtCore.QRect(50, 230, 41, 20))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.DX.setFont(font)
        self.DX.setObjectName("DX")
        self.DZ = QtWidgets.QLineEdit(self.centralwidget)
        self.DZ.setGeometry(QtCore.QRect(50, 270, 41, 20))
        font = QtGui.QFont()
        font.setPointSize(10)
        self.DZ.setFont(font)
        self.DZ.setObjectName("DZ")
        self.line_4 = QtWidgets.QFrame(self.centralwidget)
        self.line_4.setGeometry(QtCore.QRect(180, 100, 20, 91))
        self.line_4.setFrameShape(QtWidgets.QFrame.VLine)
        self.line_4.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line_4.setObjectName("line_4")
        self.line_5 = QtWidgets.QFrame(self.centralwidget)
        self.line_5.setGeometry(QtCore.QRect(180, 210, 20, 91))
        self.line_5.setFrameShape(QtWidgets.QFrame.VLine)
        self.line_5.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line_5.setObjectName("line_5")
        self.line_6 = QtWidgets.QFrame(self.centralwidget)
        self.line_6.setGeometry(QtCore.QRect(0, 220, 20, 81))
        self.line_6.setFrameShape(QtWidgets.QFrame.VLine)
        self.line_6.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line_6.setObjectName("line_6")
        self.line_7 = QtWidgets.QFrame(self.centralwidget)
        self.line_7.setGeometry(QtCore.QRect(40, 200, 151, 20))
        self.line_7.setFrameShape(QtWidgets.QFrame.HLine)
        self.line_7.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line_7.setObjectName("line_7")
        self.line_8 = QtWidgets.QFrame(self.centralwidget)
        self.line_8.setGeometry(QtCore.QRect(10, 290, 181, 20))
        self.line_8.setFrameShape(QtWidgets.QFrame.HLine)
        self.line_8.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line_8.setObjectName("line_8")
        self.label_10 = QtWidgets.QLabel(self.centralwidget)
        self.label_10.setGeometry(QtCore.QRect(10, 450, 151, 16))
        font = QtGui.QFont()
        font.setPointSize(10)
        font.setBold(True)
        font.setWeight(75)
        self.label_10.setFont(font)
        self.label_10.setObjectName("label_10")
        self.line_9 = QtWidgets.QFrame(self.centralwidget)
        self.line_9.setGeometry(QtCore.QRect(160, 450, 31, 20))
        self.line_9.setFrameShape(QtWidgets.QFrame.HLine)
        self.line_9.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line_9.setObjectName("line_9")
        self.line_10 = QtWidgets.QFrame(self.centralwidget)
        self.line_10.setGeometry(QtCore.QRect(0, 470, 20, 101))
        self.line_10.setFrameShape(QtWidgets.QFrame.VLine)
        self.line_10.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line_10.setObjectName("line_10")
        self.label_11 = QtWidgets.QLabel(self.centralwidget)
        self.label_11.setGeometry(QtCore.QRect(20, 480, 41, 16))
        font = QtGui.QFont()
        font.setPointSize(10)
        font.setBold(True)
        font.setWeight(75)
        self.label_11.setFont(font)
        self.label_11.setObjectName("label_11")
        self.line_11 = QtWidgets.QFrame(self.centralwidget)
        self.line_11.setGeometry(QtCore.QRect(10, 560, 181, 20))
        self.line_11.setFrameShape(QtWidgets.QFrame.HLine)
        self.line_11.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line_11.setObjectName("line_11")
        self.line_12 = QtWidgets.QFrame(self.centralwidget)
        self.line_12.setGeometry(QtCore.QRect(180, 460, 20, 111))
        self.line_12.setFrameShape(QtWidgets.QFrame.VLine)
        self.line_12.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line_12.setObjectName("line_12")
        self.Color = QtWidgets.QPushButton(self.centralwidget)
        self.Color.setEnabled(False)
        self.Color.setGeometry(QtCore.QRect(20, 340, 61, 31))
        palette = QtGui.QPalette()
        brush = QtGui.QBrush(QtGui.QColor(240, 14, 14))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Active, QtGui.QPalette.Button, brush)
        brush = QtGui.QBrush(QtGui.QColor(240, 14, 14))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Inactive, QtGui.QPalette.Button, brush)
        brush = QtGui.QBrush(QtGui.QColor(240, 14, 14))
        brush.setStyle(QtCore.Qt.SolidPattern)
        palette.setBrush(QtGui.QPalette.Disabled, QtGui.QPalette.Button, brush)
        self.Color.setPalette(palette)
        font = QtGui.QFont()
        font.setPointSize(8)
        self.Color.setFont(font)
        self.Color.setMouseTracking(False)
        self.Color.setText("")
        self.Color.setDefault(False)
        self.Color.setFlat(False)
        self.Color.setObjectName("Color")
        self.label_13 = QtWidgets.QLabel(self.centralwidget)
        self.label_13.setGeometry(QtCore.QRect(10, 310, 41, 16))
        font = QtGui.QFont()
        font.setPointSize(10)
        font.setBold(True)
        font.setWeight(75)
        self.label_13.setFont(font)
        self.label_13.setObjectName("label_13")
        self.line_13 = QtWidgets.QFrame(self.centralwidget)
        self.line_13.setGeometry(QtCore.QRect(50, 310, 141, 20))
        self.line_13.setFrameShape(QtWidgets.QFrame.HLine)
        self.line_13.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line_13.setObjectName("line_13")
        self.ChangeColor = QtWidgets.QPushButton(self.centralwidget)
        self.ChangeColor.setGeometry(QtCore.QRect(100, 340, 75, 31))
        font = QtGui.QFont()
        font.setPointSize(9)
        font.setBold(True)
        font.setWeight(75)
        self.ChangeColor.setFont(font)
        self.ChangeColor.setObjectName("ChangeColor")
        self.line_14 = QtWidgets.QFrame(self.centralwidget)
        self.line_14.setGeometry(QtCore.QRect(180, 320, 20, 61))
        self.line_14.setFrameShape(QtWidgets.QFrame.VLine)
        self.line_14.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line_14.setObjectName("line_14")
        self.line_15 = QtWidgets.QFrame(self.centralwidget)
        self.line_15.setGeometry(QtCore.QRect(0, 330, 20, 51))
        self.line_15.setFrameShape(QtWidgets.QFrame.VLine)
        self.line_15.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line_15.setObjectName("line_15")
        self.line_16 = QtWidgets.QFrame(self.centralwidget)
        self.line_16.setGeometry(QtCore.QRect(10, 370, 181, 20))
        self.line_16.setFrameShape(QtWidgets.QFrame.HLine)
        self.line_16.setFrameShadow(QtWidgets.QFrame.Sunken)
        self.line_16.setObjectName("line_16")
        self.DoTask = QtWidgets.QPushButton(self.centralwidget)
        self.DoTask.setGeometry(QtCore.QRect(110, 390, 81, 31))
        font = QtGui.QFont()
        font.setPointSize(9)
        font.setBold(True)
        font.setWeight(75)
        self.DoTask.setFont(font)
        self.DoTask.setObjectName("DoTask")
        self.graphicsView = QtWidgets.QGraphicsView(self.centralwidget)
        self.graphicsView.setGeometry(QtCore.QRect(210, 40, 571, 571))
        self.graphicsView.setObjectName("graphicsView")
        self.Clean = QtWidgets.QPushButton(self.centralwidget)
        self.Clean.setGeometry(QtCore.QRect(10, 390, 81, 31))
        font = QtGui.QFont()
        font.setPointSize(9)
        font.setBold(True)
        font.setWeight(75)
        self.Clean.setFont(font)
        self.Clean.setObjectName("Clean")
        self.label_14 = QtWidgets.QLabel(self.centralwidget)
        self.label_14.setGeometry(QtCore.QRect(20, 510, 41, 21))
        font = QtGui.QFont()
        font.setPointSize(10)
        font.setBold(True)
        font.setWeight(75)
        self.label_14.setFont(font)
        self.label_14.setObjectName("label_14")
        self.label_16 = QtWidgets.QLabel(self.centralwidget)
        self.label_16.setGeometry(QtCore.QRect(20, 540, 41, 21))
        font = QtGui.QFont()
        font.setPointSize(10)
        font.setBold(True)
        font.setWeight(75)
        self.label_16.setFont(font)
        self.label_16.setObjectName("label_16")
        self.angle_ox = QtWidgets.QSlider(self.centralwidget)
        self.angle_ox.setGeometry(QtCore.QRect(50, 480, 131, 19))
        self.angle_ox.setLayoutDirection(QtCore.Qt.LeftToRight)
        self.angle_ox.setMinimum(-180)
        self.angle_ox.setMaximum(180)
        self.angle_ox.setOrientation(QtCore.Qt.Horizontal)
        self.angle_ox.setObjectName("angle_ox")
        self.angle_oy = QtWidgets.QSlider(self.centralwidget)
        self.angle_oy.setGeometry(QtCore.QRect(50, 510, 131, 19))
        self.angle_oy.setMinimum(-180)
        self.angle_oy.setMaximum(180)
        self.angle_oy.setOrientation(QtCore.Qt.Horizontal)
        self.angle_oy.setObjectName("angle_oy")
        self.angle_oz = QtWidgets.QSlider(self.centralwidget)
        self.angle_oz.setGeometry(QtCore.QRect(50, 540, 131, 19))
        self.angle_oz.setMinimum(-180)
        self.angle_oz.setMaximum(180)
        self.angle_oz.setOrientation(QtCore.Qt.Horizontal)
        self.angle_oz.setObjectName("angle_oz")
        MainWindow.setCentralWidget(self.centralwidget)
        self.menubar = QtWidgets.QMenuBar(MainWindow)
        self.menubar.setGeometry(QtCore.QRect(0, 0, 800, 21))
        self.menubar.setObjectName("menubar")
        MainWindow.setMenuBar(self.menubar)
        self.statusbar = QtWidgets.QStatusBar(MainWindow)
        self.statusbar.setObjectName("statusbar")
        MainWindow.setStatusBar(self.statusbar)

        self.retranslateUi(MainWindow)
        QtCore.QMetaObject.connectSlotsByName(MainWindow)

    def retranslateUi(self, MainWindow):
        _translate = QtCore.QCoreApplication.translate
        MainWindow.setWindowTitle(_translate("MainWindow", "MainWindow"))
        self.label.setText(_translate("MainWindow", "Алгоритм плавающего горизонта"))
        self.Funcs.setItemText(0, _translate("MainWindow", "y = 5x + 3z - 7"))
        self.Funcs.setItemText(1, _translate("MainWindow", "y = x^2 + z^2"))
        self.Funcs.setItemText(2, _translate("MainWindow", "y = x^2 - 2z^2"))
        self.Funcs.setItemText(3, _translate("MainWindow", "y = sin(x * z)"))
        self.Funcs.setItemText(4, _translate("MainWindow", "y = x^2 * z"))
        self.Funcs.setItemText(5, _translate("MainWindow", "y = (x * z)^2"))
        self.label_2.setText(_translate("MainWindow", "Поверхность:"))
        self.label_3.setText(_translate("MainWindow", "Пределы:"))
        self.label_4.setText(_translate("MainWindow", "х"))
        self.XStart.setText(_translate("MainWindow", "-1"))
        self.XEnd.setText(_translate("MainWindow", "1"))
        self.ZStart.setText(_translate("MainWindow", "-1"))
        self.ZEnd.setText(_translate("MainWindow", "1"))
        self.label_6.setText(_translate("MainWindow", "z"))
        self.label_7.setText(_translate("MainWindow", "Шаг:"))
        self.label_8.setText(_translate("MainWindow", "dх"))
        self.label_9.setText(_translate("MainWindow", "dz"))
        self.DX.setText(_translate("MainWindow", "1"))
        self.DZ.setText(_translate("MainWindow", "1"))
        self.label_10.setText(_translate("MainWindow", "Поворот вокруг осей:"))
        self.label_11.setText(_translate("MainWindow", "OX:"))
        self.label_13.setText(_translate("MainWindow", "Цвет:"))
        self.ChangeColor.setText(_translate("MainWindow", "Изменить"))
        self.DoTask.setText(_translate("MainWindow", "Выполнить"))
        self.Clean.setText(_translate("MainWindow", "Очистить"))
        self.label_14.setText(_translate("MainWindow", "OY:"))
        self.label_16.setText(_translate("MainWindow", "OZ:"))

