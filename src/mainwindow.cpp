/**************************************************************************
 *                                                                        *
 *   Author: Ivo Filot <i.a.w.filot@tue.nl>                               *
 *                                                                        *
 *   LaFluxxy is free software:                                           *
 *   you can redistribute it and/or modify it under the terms of the      *
 *   GNU General Public License as published by the Free Software         *
 *   Foundation, either version 3 of the License, or (at your option)     *
 *   any later version.                                                   *
 *                                                                        *
 *   LaFluxxy is distributed in the hope that it will be useful,          *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty          *
 *   of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.              *
 *   See the GNU General Public License for more details.                 *
 *                                                                        *
 *   You should have received a copy of the GNU General Public License    *
 *   along with this program.  If not, see http://www.gnu.org/licenses/.  *
 *                                                                        *
 **************************************************************************/

#include "mainwindow.h"
#include "config.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    // set Window icon
    this->setWindowIcon(QIcon(QCoreApplication::applicationDirPath() + "/../lafluxxy_logo.ico"));

    //build drop-down menu
    this->build_menu();

    QWidget *widget = new QWidget();
    this->setCentralWidget(widget);

    // create tabs
    this->create_tabs();

    // create vertical layout
    QVBoxLayout *layout = new QVBoxLayout();
    // layout->setMargin(5);
    layout->addWidget(this->tabs);
    widget->setLayout(layout);

    // display status message
    statusBar()->showMessage(tr("Welcome to ") + tr(PROGRAM_NAME));

    // set window parameters
    this->setWindowTitle(tr(PROGRAM_NAME) + tr(" v.") + QString(PROGRAM_VERSION));    // set window label
    this->setMinimumSize(1280, 800);                     // set minimum size of the window
    this->resize(1280, 800);                             // resize the windows

    // build connections
    connect(this->input_tab->get_button_submit(), SIGNAL(clicked()), this, SLOT(launch_calculation()));
    connect(this->input_tab->get_button_select_maze(), SIGNAL(clicked()), this, SLOT(press_build_and_select_maze()));
    connect(this->maze_tab, SIGNAL(signal_mazes_generated()), this, SLOT(connect_maze_build_button()));
    connect(this->results_tab->get_button_copy_to_movie(), SIGNAL(released()), this, SLOT(copy_data_to_movietab()));
}

/**
 * @brief      Destroys the object.
 */
MainWindow::~MainWindow(){}

/**
 * @brief      Connect the maze build button to the action
 */
void MainWindow::connect_maze_build_button() {
    connect(this->maze_tab->get_button_select_maze(), SIGNAL(released()), this, SLOT(press_select_maze()));
}

/**
 * @brief      Close the application
 */
void MainWindow::exit() {
    QApplication::quit();
}

/**
 * @brief      Gives About pop-up window
 */
void MainWindow::about() {
    QMessageBox message_box;
    message_box.setText(tr("<html><h2>") +
                        tr(PROGRAM_NAME) + tr(" ") + tr(PROGRAM_VERSION) +
                        tr("</h2><p><b>Authors:</b><ul><li>Ivo Filot</li>") +
                        tr("<li>Anouk de Leeuw den Bouter</li>") +
                        tr("<li>Roos Krösschell</li>") +
                        tr("<li>Fabiënne Lucas</li>") +
                        tr("</ul></p><p>") + tr(PROGRAM_NAME) + tr(" is licensed under the GPLv3 license.</p>") +
                        tr("<p>") + tr(PROGRAM_NAME) + tr(" is dynamically linked to Qt, which is licensed under LGPLv3.</p>") +
                        tr("<p>Color schemes have been obtained from Matplotlib - <a href=\"https://matplotlib.org/index.html\">https://matplotlib.org/index.html</a>.</p>") +
                        tr("</html>"));
    message_box.setIcon(QMessageBox::Information);
    message_box.setWindowTitle(tr("About ") + tr(PROGRAM_NAME));
    message_box.exec();
}

/**
 * @brief      Gives About pop-up window
 */
void MainWindow::acknowledgements() {
    QMessageBox message_box;
    message_box.setText(tr("Acknowledgments"));
    message_box.setIcon(QMessageBox::Information);
    message_box.setText(tr("<html><h1>Acknowledgments</h1><p>The following people are gratefully acknowledged for contributing to ") + PROGRAM_NAME +
                               tr("</p><p><b>Beta testing & feedback</b><ul><li>Bart Zijlstra</li><li>Robin Broos</li><li>Jasper Bouwman</li></ul></p>") +
                               tr("<p><b>Exploration of open-source software licenses</b></p>")+
                               tr("<ul><li>Stacey Fun</li><li>Frank van Hertrooij</li><li>Esmee de Korver</li><li>Chantal Petit</li><li>Lisa Cattenstart</li></ul>") +
                               tr("</html>"));
    message_box.exec();
}

/**
 * @brief      Launch the simulation
 */
void MainWindow::launch_calculation() {
    if(this->results_tab->get_num_frames() > 0) {
        QMessageBox msgBox;
        msgBox.setText(tr("<b>Warning</b>: This action will delete all previous simulation results!"));
        msgBox.setInformativeText(tr("A previous set of simulation results exists. Continuing will discard these results.<br><br><b>Are you sure you wish to continue?</b>"));
        msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.setIcon(QMessageBox::Warning);
        int ret = msgBox.exec();

        if(ret == QMessageBox::Cancel) {
            return;
        }
    }

    this->results_tab->clear();
    this->tdrd = std::unique_ptr<TwoDimRD>(this->input_tab->build_reaction_system());
    this->results_tab->set_reaction_system(this->tdrd.get());

    this->input_tab->get_button_submit()->setEnabled(false);
    this->results_tab->get_stop_button()->setEnabled(true);

    // already set initial conditions image
    this->results_tab->update_progress(0, this->tdrd->get_num_steps());
    this->results_tab->add_frame(0);

    WorkerThread *workerThread = new WorkerThread(this->tdrd.get());
    connect(workerThread, &WorkerThread::simulation_finished, this, &MainWindow::handle_simulation_finished);
    connect(workerThread, &WorkerThread::simulation_cancelled, this, &MainWindow::handle_simulation_canceled);
    connect(workerThread, &WorkerThread::step_finished, this, &MainWindow::handle_results_step);
    connect(workerThread, &WorkerThread::finished, workerThread, &QObject::deleteLater);
    connect(this->results_tab->get_stop_button(), SIGNAL(clicked()), workerThread, SLOT(kill_job()));
    workerThread->start();

    this->tabs->setCurrentIndex(this->tabs->indexOf(this->results_tab));
    statusBar()->showMessage(tr("Simulation running..."));
}

/**
 * @brief      Handle results when the simulation is finished
 */
void MainWindow::handle_simulation_finished() {
    this->input_tab->get_button_submit()->setEnabled(true);
    this->results_tab->get_stop_button()->setEnabled(false);
    statusBar()->showMessage(tr("Simulation complete."));
}

/**
 * @brief      Handle results when the simulation is cancelled
 */
void MainWindow::handle_simulation_canceled() {
    this->input_tab->get_button_submit()->setEnabled(true);
    this->results_tab->get_stop_button()->setEnabled(false);
    statusBar()->showMessage(tr("Simulation canceled."));
}

/**
 * @brief      Handle the results of a single frame
 *
 * @param[in]  i      Frame index i
 * @param[in]  tcalc  Number of seconds spent on step
 */
void MainWindow::handle_results_step(unsigned int i, double tcalc) {
    this->results_tab->update_progress(i+1, this->tdrd->get_num_steps());
    this->results_tab->add_frame(i+1, tcalc);
}

/**
 * @brief      Create tabs
 */
void MainWindow::create_tabs() {
    this->tabs = new QTabWidget();
    this->input_tab = new InputTab();
    this->tabs->addTab(this->input_tab, tr("Input"));
    this->tabs->setTabIcon(0, QIcon(":/assets/icons/16/formula.png"));

    this->maze_tab = new MazeTab();
    this->tabs->addTab(this->maze_tab, tr("Maze"));
    this->tabs->setTabIcon(1, QIcon(":/assets/icons/16/maze.png"));

    this->results_tab = new ResultsTab();
    this->tabs->addTab(this->results_tab, tr("Results"));
    this->tabs->setTabIcon(2, QIcon(":/assets/icons/16/binary.png"));

    this->movie_tab = new MovieTab();
    this->tabs->addTab(this->movie_tab, tr("Movie"));
    this->tabs->setTabIcon(3, QIcon(":/assets/icons/16/video.png"));
}

/**
 * @brief      Build the drop-down menus
 */
void MainWindow::build_menu() {
    // build drop down menus
    QMenuBar *menuBar = new QMenuBar;
    QMenu *menuFile = menuBar->addMenu(tr("&File"));
    QMenu *menuHelp = menuBar->addMenu(tr("&Help"));

    // build menu bar items
    QAction *action_open = new QAction(menuFile);
    QAction *action_save = new QAction(menuFile);
    QAction *action_quit = new QAction(menuFile);
    QAction *action_about = new QAction(menuHelp);
    QAction *action_acknowledgements = new QAction(menuHelp);

    // define actions
    action_open->setText(tr("Open"));
    action_open->setShortcuts(QKeySequence::Open);

    action_save->setText(tr("Save"));
    action_save->setShortcuts(QKeySequence::Save);

    action_quit->setText(tr("Quit"));
    action_quit->setShortcuts(QKeySequence::Quit);

    action_about->setText(tr("About"));

    action_acknowledgements->setText(tr("Acknowledgements"));

    // add options to menu
    // menuFile->addAction(action_open);
    // menuFile->addAction(action_save);
    menuFile->addAction(action_quit);
    menuHelp->addAction(action_acknowledgements);
    menuHelp->addSeparator();
    menuHelp->addAction(action_about);

    // connect actions
    connect(action_quit, &QAction::triggered, this, &MainWindow::exit);
    connect(action_about, &QAction::triggered, this, &MainWindow::about);
    connect(action_acknowledgements, &QAction::triggered, this, &MainWindow::acknowledgements);

    setMenuBar(menuBar);
}

/**
 * @brief      Action pressing build and select maze button
 */
void MainWindow::press_build_and_select_maze() {
    this->tabs->setCurrentIndex(this->tabs->indexOf(this->maze_tab));
}

/**
 * @brief      Connect pre-generated maze to simulation
 */
void MainWindow::press_select_maze() {
    Maze* maze = this->maze_tab->get_maze();
    if(maze != nullptr) {
        this->input_tab->set_maze(new Maze(*maze));
        this->tabs->setCurrentIndex(this->tabs->indexOf(this->input_tab));
    }
}

/**
 * @brief      Copy all results to movietab
 */
void MainWindow::copy_data_to_movietab() {
    this->movie_tab->set_concentrations(this->tdrd->get_concentrations(true), this->tdrd->get_concentrations(false), this->tdrd->get_mask());
    this->tabs->setCurrentIndex(this->tabs->indexOf(this->movie_tab));
}
