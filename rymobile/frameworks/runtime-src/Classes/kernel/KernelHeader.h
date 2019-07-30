#ifndef KERNELHEADER_H_
#define KERNELHEADER_H_

#include "kernel/game/CClientKernel.h"
#include "kernel/game/IClientKernel.h"
#include "kernel/game/IClientKernelSink.h"

#include "kernel/user/ClientUserManager.h"
#include "kernel/user/IClientUserItem.h"
#include "kernel/user/IUserManagerSink.h"

#include "kernel/server/CServerItem.h"
#include "kernel/server/IServerItem.h"
#include "kernel/server/IServerItemSink.h"
#include "kernel/server/ITableViewFrame.h"
#include "kernel/server/TableViewFrame.h"

#include "kernel/IChatSink.h"
#include "kernel/IGameFrameSink.h"
#include "kernel/IRoomFrameSink.h"
#include "kernel/IStringMessageSink.h"

#include "Kernel/network/CSocketEngine.h"
#include "Kernel/network/CSocketMission.h"
#include "Kernel/network/ISocketEngine.h"
#include "Kernel/network/ISocketEngineSink.h"
#include "Kernel/network/QPCipher.h"

#include "Kernel/socket/Socket.h"

#endif
