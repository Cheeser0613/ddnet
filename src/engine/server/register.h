#ifndef ENGINE_SERVER_REGISTER_H
#define ENGINE_SERVER_REGISTER_H

class CConfig;
class IConsole;
class IEngine;
struct CNetChunk;

class IRegister
{
public:
	virtual ~IRegister() {}

	virtual void Update() = 0;
	// Call `OnConfigChange` if you change relevant config variables
	// without going through the console.
	virtual void OnConfigChange() = 0;
	// Returns `true` if the packet was a packet related to registering
	// code and doesn't have to processed furtherly.
	virtual bool OnPacket(CNetChunk *pPacket) = 0;
	// `pInfo` must be an encoded JSON object.
	virtual void OnNewInfo(const char *pInfo) = 0;
};

IRegister *CreateRegister(CConfig *pConfig, IConsole *pConsole, IEngine *pEngine, int ServerPort, unsigned SixupGlobalSecurityToken);

#endif
