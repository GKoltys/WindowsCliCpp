#ifndef CONFIG_H
#define CONFIG_H

// Need to review
class Config
{
protected:
    const bool isDebugMode() const;
    void enableDebugMode();
    void disableDebugMode();

private:
    bool _debugMode;
};

#endif