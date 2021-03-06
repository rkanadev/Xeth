#include "AccountScanCriterion.hpp"

namespace Xeth{

AccountScanCriterion::AccountScanCriterion(const char *address) :
    ScanCriterion(address)
{
    HexAddressNormalizer normalizer;
    normalizer(_address, _address);
    _address.insert(0, "0x"); //add prefix
}

void AccountScanCriterion::processHeader
(
    size_t,
    const std::string &hash,
    const std::string &miner,
    const BigInt &amount,
    time_t timestamp,
    ScanResult &result
)
{
    if(miner == _address && _address.size())
    {
        saveTransaction(TransactionCategory::Mined, hash, "", miner, amount, timestamp, result);
    }
}

void AccountScanCriterion::processTransaction
(
    const std::string &hash,
    const std::string &from,
    const std::string &to,
    const BigInt &amount,
    const std::string &,
    time_t timestamp,
    ScanResult &result
)
{
    if(_address.size())
    {
        if(from == _address)
        {
            saveTransaction(TransactionCategory::Sent, hash, from, to, amount, timestamp, result);
        }
        else if(to == _address)
        {
            saveTransaction(TransactionCategory::Received, hash, from, to, amount, timestamp, result);
        }
    }
}

void AccountScanCriterion::saveTransaction
(
    const TransactionCategory &category,
    const std::string &hash,
    const std::string &from,
    const std::string &to,
    const BigInt &amount,
    time_t timestamp,
    ScanResult &result
)
{
    QJsonObject obj;
    obj.insert("category", QString(category.toString()));
    obj.insert("hash", QString(hash.c_str()));
    if(from.size())
    {
        obj.insert("from",  QString(from.c_str()));
    }
    obj.insert("to", QString(to.c_str()));
    obj.insert("amount", QString(boost::lexical_cast<std::string>(amount).c_str()));
    obj.insert("timestamp", (qint64)timestamp);

    result.transactions.push_back(obj);
}





}
