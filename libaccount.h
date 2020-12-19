#ifndef _LIBACCOUNT_H_
#define _LIBACCOUNT_H_
	#include<string>
	#include<deque>
	#include<utility>
	typedef std::pair<double,std::string> AccountItem;
	class Account{
		virtual ~Account()=default;
		virtual void add_item(double price,const char *describe){
			add_item(std::make_pair(price,std::string(describe)));
		}
		virtual void add_item(double price,const std::string &describe){
			add_item(std::make_pair(price,describe));
		}
		virtual void add_item(double price,std::string &&describe){
			add_item(std::make_pair(price,describe));
		}
		virtual void add_item(const AccountItem &item){
			add_item(AccountItem(item));
		}
		virtual void add_item(AccountItem &&item)=0;
		virtual double get_total()const=0;
		virtual std::deque<AccountItem> get_info(size_t size=25,size_t first=0);
	};
#endif