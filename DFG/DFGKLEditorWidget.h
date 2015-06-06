// Copyright 2010-2015 Fabric Software Inc. All rights reserved.

#ifndef __UI_DFG_DFGKLEditorWidget__
#define __UI_DFG_DFGKLEditorWidget__

#include <QtGui/QWidget>
#include <QtGui/QPlainTextEdit>
#include <KLEditor/KLEditorWidget.h>
#include "DFGConfig.h"
#include "DFGController.h"
#include "DFGKLEditorPortTableWidget.h"

namespace FabricUI
{

  namespace DFG
  {

    class DFGKLEditorWidget : public QWidget
    {
      Q_OBJECT

    public:

      DFGKLEditorWidget(QWidget * parent, DFGController * controller, FabricServices::ASTWrapper::KLASTManager * manager, const DFGConfig & config = DFGConfig());
      virtual ~DFGKLEditorWidget();

      void setFunc(FabricCore::DFGExec func, char const * execPath);
      bool hasUnsavedChanges() const { return m_unsavedChanges; }
      KLEditor::KLEditorWidget * klEditor() { return m_klEditor; }

      virtual void closeEvent(QCloseEvent * event);

    public slots:

      void onExecPortsChanged();
      void compile();
      void reload();
      void onNewUnsavedChanges();

    private:

      FabricCore::DFGExec m_func;
      std::string m_execPath;
      DFGController * m_controller;
      DFGKLEditorPortTableWidget * m_ports;
      KLEditor::KLEditorWidget * m_klEditor;
      DFGConfig m_config;
      bool m_unsavedChanges;
    };

  };

};

#endif // __UI_DFG_DFGKLEditorWidget__
