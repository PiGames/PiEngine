#pragma once

#include <fstream>
#include <iostream>
#include <string>

#include "engine/console/Console.hpp"

namespace pi
{
	// Logger class
	// First, initialize it with init() method, then use log() to log messages
	class Logger final
	{
	public:
		enum class MessageType
		{
			Separator = 0,
			Info,
			Warning,
			Error,
			Assert
		};

		enum class OutputType
		{
			Console = 0,
			File,
			Both
		};

		Logger() = delete;
		static void Init( const std::string& outputFileName = "output.txt", Console* console = nullptr );
		static void Log( const std::string& message, MessageType messageType = MessageType::Info, OutputType outputType = OutputType::Both );

	private:
		static std::ofstream file;
		static Console* console;

		static void logToFile( const std::string& message );
		static void logToConsole( const std::string& message );
	};
}

