#ifndef FQ_STRATEGY_ACCOUNT_H
#define FQ_STRATEGY_ACCOUNT_H

#include <vector>

namespace FreeQuant {

class Portfolio;
class Currency;

class Account {
public:
	explicit Account();
	virtual ~Account();

private:
    std::vector<Portfolio *> mPortfolios;
	Currency *mCurrency;
	double mQuantity;
	//"Additions", "Withdrawals",  "Realized.PL", "Unrealized.PL", "Int.Income", "Gross.Trading.PL",
  //  "Txn.Fees", "Net.Trading.PL", "Advisory.Fees", "Net.Performance",  "End.Eq"
};

} // namespace FreeQuant

#endif /* ACCOUNT_H */