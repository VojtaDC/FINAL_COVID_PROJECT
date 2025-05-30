#pragma once
#include <QSortFilterProxyModel>

class PatientFilterModel : public QSortFilterProxyModel {
	Q_OBJECT

public:
	explicit PatientFilterModel(QObject* parent = nullptr);

public slots:
	void setSearch(const QString& _text);
	void setOption(const QString& _option);

protected:
	bool filterAcceptsRow(int _sourcerow, const QModelIndex& _sourceparent) const override;

private:
	QString m_search;
	QString m_option;
};
