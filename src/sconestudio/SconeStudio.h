/*
** SconeStudio.h
**
** Copyright (C) 2013-2019 Thomas Geijtenbeek and contributors. All rights reserved.
**
** This file is part of SCONE. For more information, see http://scone.software.
*/

#ifndef SCONESTUDIO_H
#define SCONESTUDIO_H

#include <QtCore/QtGlobal>
#include <QtCore/QTimer>
#include <QtCore/QProcess>
#include <QtWidgets/QMainWindow>

#include "ui_SconeStudio.h"

#include "scone/core/PropNode.h"
#include "scone/core/Statistic.h"

#include "xo/time/timer.h"
#include "xo/numerical/delta.h"
#include "ProgressDockWidget.h"
#include "QCodeEditor.h"
#include "SettingsEditor.h"
#include "xo/system/log_sink.h"
#include "QCompositeMainWindow.h"
#include "QDataAnalysisView.h"
#include "ResultsFileSystemModel.h"
#include "StudioModel.h"
#include "vis/plane.h"
#include "vis/vis_api.h"
#include "xo/container/flat_map.h"
#include "SconeStorageDataModel.h"

using scone::TimeInSeconds;

class SconeStudio : public QCompositeMainWindow
{
	Q_OBJECT

public:
	SconeStudio(QWidget *parent = 0, Qt::WindowFlags flags = 0);
	~SconeStudio();

	bool init();
	virtual void openFile( const QString& filename ) override;
	virtual bool tryExit() override;

public slots:
	void runSimulation( const QString& filename );
	void activateBrowserItem( QModelIndex idx );
	void selectBrowserItem( const QModelIndex& idx, const QModelIndex& idxold );
	void resultsSelectionChanged( const QItemSelection& newitem, const QItemSelection& olditem ) {}
	void start();
	void stop();
	void refreshAnalysis();

	virtual void fileOpenTriggered() override;
	virtual void fileSaveTriggered() override;
	virtual void fileSaveAsTriggered() override;
	virtual void fileCloseTriggered() override;

	void helpAbout() {}
	void runScenario();
	void performanceTest();
	void optimizeScenario();
	void optimizeScenarioMultiple();
	void abortOptimizations();
	void updateBackgroundTimer();
	void updateOptimizations();
	void createVideo();
	void captureImage();
	void tabCloseRequested( int idx );
	void updateViewSettings();
	void showSettingsDialog() { settings.showDialog( this ); }
	void setPlaybackTime( TimeInSeconds t ) { setTime( t, true ); }
	void updateTabTitles();
	void findDialog() { if ( auto* e = getActiveScenario() ) e->findDialog(); }
	void findNext() { if ( auto* e = getActiveScenario() ) e->findNext(); }
	void findPrevious() { if ( auto* e = getActiveScenario() ) e->findNext( true ); }

public:
	bool close_all;
	bool isRecording() { return !captureFilename.isEmpty(); }
	bool isEvalutating() { return model_ && model_->IsEvaluating(); }

private:
	QCodeEditor* getActiveScenario();
	QCodeEditor* getVerifiedActiveScenario();
	void evaluate();
	void setTime( TimeInSeconds t, bool update_vis );
	bool requestSaveChanges( QCodeEditor* s );
	int getTabIndex( QCodeEditor* s );
	void addProgressDock( ProgressDockWidget* pdw );

	xo::flat_map< scone::StudioModel::ViewSettings, QAction* > viewActions;

	vis::scene scene_;
	vis::plane ground_plane;
	std::unique_ptr< scone::StudioModel > model_;

	bool createModel( const String& par_file, bool force_evaluation = false );

	Ui::SconeStudioClass ui;

	QTimer backgroundUpdateTimer;

	double slomo_factor;
	TimeInSeconds current_time;
	TimeInSeconds evaluation_time_step;
	xo::delta< scone::Vec3 > com_delta;

	QString currentParFile;

	std::vector< ProgressDockWidget* > optimizations;
	std::vector< QCodeEditor* > scenarios;

	SconeStorageDataModel storageModel;
	QDataAnalysisView* analysisView;

	ResultsFileSystemModel* resultsModel;
	QString captureFilename;
	QProcess* captureProcess;
	QDir captureImageDir;
	void finalizeCapture();

	scone::SettingsEditor settings;
};

#endif // SCONESTUDIO_H
