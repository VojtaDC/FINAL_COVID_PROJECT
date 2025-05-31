#include "patient_filter_model.h"

PatientFilterModel::PatientFilterModel(QObject* parent) : QSortFilterProxyModel(parent) {
}

void PatientFilterModel::setSearch(const QString& _search) {
	m_search = _search;
	invalidateFilter(); //method from QSortFilterProxyModel which should be used when implementing custom filtering and the filter parameter has been changed
}

void PatientFilterModel::setOption(const QString& _option) {
	m_option = _option;
	invalidateFilter();
}

bool PatientFilterModel::filterAcceptsRow(int _sourcerow, const QModelIndex& _sourceparent) const { //method from QSortFilterProxyModel that we override to make the custom filter. Returns true if the row matches the filter and thus should be displayed
	QModelIndex fullname_index = sourceModel()->index(_sourcerow, 0, _sourceparent); //QSortFilterProxyModel operates on a source model (m_model) and this model has rows and columns which contain data. This gives the index where the data to be checked is located
	QModelIndex option_index = sourceModel()->index(_sourcerow, 1, _sourceparent);

	QString fullname = sourceModel()->data(fullname_index).toString(); //This gives the data, from the source model, which needs to be check
	QString option = sourceModel()->data(option_index).toString();

	if (!fullname.contains(m_search, Qt::CaseInsensitive)) {
		return false;
	}

	if (m_option == "Positive" && option != "Yes") {
		return false;
	}

	if (m_option == "Negative" && option != "No") {
		return false;
	}

	return true;
}
