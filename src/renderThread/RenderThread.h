#pragma once

#include <atomic>
#include "ConcurrentQueue.h"
#include "../renderer/Renderer.h"
#include <memory>
#include <cstdint>

struct RenderCommand
{
	enum RenderCommandType
	{
		startFrame,
		putPixel,
		endFrame,
		drawBox,
		nCommands
	} m_command;

	int m_x{ 0 }, m_y{ 0 }, m_w{ 0 }, m_h{ 0 };
	uint32_t m_color{ 0 };

	// Ctor with command.
	explicit RenderCommand(int cmd)
		: RenderCommand(cmd, 0, 0, 0, 0, 0)
	{ }

	// Ctor with params.
	explicit RenderCommand(int cmd, int x, int y, int w, int h, uint32_t color)
		: m_command{static_cast<RenderCommandType>(cmd)}
		, m_x{ x }
		, m_y{ y }
		, m_w{ w }
		, m_h{ h }
		, m_color{ color }
	{ }
};

namespace std
{
	class thread;
}

struct RenderThread
{
	// Start.
	void start();

	// Stop.
	void stop();

	// PushCommand.
	void push_command(const RenderCommand& command);

	// Get pendingFrames
	inline uint8_t getPending() const { return m_pendingFrames; }

private:
	// 
	std::atomic<uint8_t> m_pendingFrames{ 0 };

	// Main.
	void renderMain();

	// Thread.
	std::unique_ptr<std::thread> m_thread{ nullptr };

	// Quit or not.
	std::atomic_bool quitRequested{ false };

	// Commnad queue.
	Queue<RenderCommand> m_commandQueue;
};

