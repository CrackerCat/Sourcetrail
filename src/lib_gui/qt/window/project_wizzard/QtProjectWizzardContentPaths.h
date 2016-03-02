#ifndef QT_PROJECT_WIZZARD_CONTENT_PATHS_H
#define QT_PROJECT_WIZZARD_CONTENT_PATHS_H

#include <QPushButton>

#include "qt/window/project_wizzard/QtProjectWizzardContent.h"

class QtDirectoryListBox;

class QtProjectWizzardContentPaths
	: public QtProjectWizzardContent
{
	Q_OBJECT

signals:
	void showSourceFiles();

public:
	QtProjectWizzardContentPaths(ProjectSettings* settings, QtProjectWizzardWindow* window);

	// QtSettingsWindow implementation
	virtual void populateWindow(QGridLayout* layout) override;
	void populateLayout(QGridLayout* layout, int& row);
	virtual void populateForm(QGridLayout* layout, int& row) override;

	virtual void load() override;
	virtual void save() override;
	virtual bool check() override;

	virtual QSize preferredWindowSize() const override;

	virtual void loadPaths();
	virtual void savePaths();
	virtual bool checkPaths();

protected:
	void setInfo(const QString& title, const QString& description, const QString& help);
	void setTitleString(const QString& title);
	void setDescriptionString(const QString& description);
	void setHelpString(const QString& help);

	QtDirectoryListBox* m_list;
	QtProjectWizzardContentPaths* m_subPaths;

	bool m_addShowSourcesButton;

private slots:
	void showSourcesClicked();

private:
	void addSourcesButton(QGridLayout* layout, int& row);

	QString m_titleString;
	QString m_descriptionString;
	QString m_helpString;
};


class QtProjectWizzardContentPathsSource
	: public QtProjectWizzardContentPaths
{
public:
	QtProjectWizzardContentPathsSource(ProjectSettings* settings, QtProjectWizzardWindow* window);

	// QtProjectWizzardContent implementation
	virtual QSize preferredWindowSize() const override;

	// QtProjectWizzardContentPaths implementation
	virtual void loadPaths() override;
	virtual void savePaths() override;
	virtual bool checkPaths() override;
};

class QtProjectWizzardContentPathsSourceSimple
	: public QtProjectWizzardContentPathsSource
{
public:
	QtProjectWizzardContentPathsSourceSimple(ProjectSettings* settings, QtProjectWizzardWindow* window);
};


class QtProjectWizzardContentPathsHeaderSearch
	: public QtProjectWizzardContentPaths
{
public:
	QtProjectWizzardContentPathsHeaderSearch(ProjectSettings* settings, QtProjectWizzardWindow* window);

	// QtProjectWizzardContent implementation
	virtual void loadPaths() override;
	virtual void savePaths() override;

	virtual bool isScrollAble() const override;
};

class QtProjectWizzardContentPathsHeaderSearchSimple
	: public QtProjectWizzardContentPathsHeaderSearch
{
public:
	QtProjectWizzardContentPathsHeaderSearchSimple(ProjectSettings* settings, QtProjectWizzardWindow* window);
};

class QtProjectWizzardContentPathsHeaderSearchGlobal
	: public QtProjectWizzardContentPaths
{
public:
	QtProjectWizzardContentPathsHeaderSearchGlobal(ProjectSettings* settings, QtProjectWizzardWindow* window);

	// QtProjectWizzardContent implementation
	virtual void loadPaths() override;
	virtual void savePaths() override;
};


class QtProjectWizzardContentPathsFrameworkSearch
	: public QtProjectWizzardContentPaths
{
public:
	QtProjectWizzardContentPathsFrameworkSearch(ProjectSettings* settings, QtProjectWizzardWindow* window);

	// QtProjectWizzardContent implementation
	virtual void loadPaths() override;
	virtual void savePaths() override;

	virtual bool isScrollAble() const override;
};

class QtProjectWizzardContentPathsFrameworkSearchGlobal
	: public QtProjectWizzardContentPaths
{
public:
	QtProjectWizzardContentPathsFrameworkSearchGlobal(ProjectSettings* settings, QtProjectWizzardWindow* window);

	// QtProjectWizzardContent implementation
	virtual void loadPaths() override;
	virtual void savePaths() override;
};

#endif // QT_PROJECT_WIZZARD_CONTENT_PATHS_H
