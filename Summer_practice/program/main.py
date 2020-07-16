import sys
from my_gui import *

app, application = None, None

class MainWin(QtWidgets.QMainWindow):
    def __init__(self):
        super().__init__()
        self.ui = GuiMainWin()
        self.ui.setupUi(self)

def main():
    global app, application
    app = QtWidgets.QApplication([])
    application = MainWin()
    application.show()

    sys.exit(app.exec())

main()