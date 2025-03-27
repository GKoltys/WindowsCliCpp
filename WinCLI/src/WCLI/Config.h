#ifndef CONFIG_H
#define CONFIG_H

class Config
{
protected:
    bool isDebugMode() const;
    void enableDebugMode();
    void disableDebugMode();

private:
    bool _debugMode;
};

#endif