#ifndef DATASTATEHELPER_HPP
#define DATASTATEHELPER_HPP

#include <QModelIndex>
#include <QStack>
#include <QVariant>
#include <QVector>

class MonoState {
public:
    QModelIndex index;
    QVariant oldValue;
    QVariant newValue;
    int role;

    MonoState();

    explicit MonoState(const QModelIndex& index, const QVariant& oldValue,
                       const QVariant& newValue, int role);
};

class DataStateHelper {
public:
    DataStateHelper();

    void pushGroup();
    void popGroup();

    void setEnabled(bool enabled);

    void saveState(const QModelIndex& index, const QVariant& oldValue,
                   const QVariant& newValue, int role);

    bool canUndo() const;
    bool canRedo() const;

    QVector<MonoState> undo();
    QVector<MonoState> redo();

private:
    bool enabled_;
    bool pushedGroup_;
    QStack<QVector<MonoState>> stateGroups_;
    QStack<QVector<MonoState>> undoneStateGroups_;
};

#endif // DATASTATEHELPER_HPP
