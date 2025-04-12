#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H

class Cd;
class Cls;
class Dir;
class Echo;
class Exit;
class Help;
class Popd;
class Pushd;

class CommandManager
{
public:
    CommandManager();
    ~CommandManager();

    void executeCommand(CliContext& ctx, const std::vector<std::string>& args);

private:
    Cd* _cd;
    Cls* _cls;
    Dir* _dir;
    Echo* _echo;
    Exit* _exit;
    Help* _help;
    Popd* _popd;
    Pushd* _pushd;
};

#endif