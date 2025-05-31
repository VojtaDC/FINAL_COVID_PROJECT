#pragma once
#include <QSortFilterProxyModel>

class PatientFilterModel :public QSortFilterProxyModel {
	Q_OBJECT

public:
	explicit PatientFilterModel(QObject* parent = nullptr);

public slots:
	void setSearch(const QString& _text);
	void setOption(const QString& _option);

protected:
	bool filterAcceptsRow(int _sourcerow, const QModelIndex& _sourceparent) const override;  //method from QSortFilterProxyModel that we override to make the custom filter. Returns true if the row matches the filter and thus should be displayed
																												// is in protected because in the base class (QSortFilterProxyModel) it is also in protected
private:
	QString m_search;
	QString m_option;
};

