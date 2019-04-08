#pragma once

enum SpyAgentStatus { Spy, Fighter };

enum VoteforCreation { UnknownCreate, Create, Break };

enum VoteforExecution { UnknownExec, Execute, Fail };

enum MissionResult { UnknownRes, VoteUp, VoteDown, Executed, Failed };

class GameAgents; //Forward Declare
