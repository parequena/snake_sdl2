#include "RenderThread.h"
#include <thread>

// Start.
void RenderThread::start()
{
	// m_thread = new std::thread(&RenderThread::renderMain, this);
	quitRequested = false;
	m_thread = std::make_unique<std::thread>(&RenderThread::renderMain, this);
}

// Stop.
void RenderThread::stop()
{
	if (m_thread)
	{
		quitRequested = true;
		push_command(RenderCommand{ 1 });
		m_thread->join();
		m_thread = nullptr;
	}
}

// PushCommand.
void RenderThread::push_command(const RenderCommand& command)
{
	if (command.m_command == RenderCommand::endFrame) ++m_pendingFrames;
	m_commandQueue.push(command);
}

#include <iostream>
// -------------------------------------------------- PRIVATE
// Main.
void RenderThread::renderMain()
{
	while(!quitRequested)
	{
		const auto command{ m_commandQueue.pop() };

		switch (command.m_command)
		{
		case RenderCommand::startFrame: // 0
			Renderer::Clear(command.m_color);
		break;

		case RenderCommand::putPixel: // 1
			Renderer::PutPixel(command.m_x, command.m_y, command.m_color);
		break;

		case RenderCommand::endFrame: // 2
			Renderer::Present();
			--m_pendingFrames;
		break;

		case RenderCommand::drawBox: // 3
			for (auto y = command.m_y - command.m_h; y <= command.m_y + command.m_h; ++y)
			{
				for (auto x = command.m_x - command.m_w; x <= command.m_x + command.m_w; ++x)
				{
					Renderer::PutPixel(x, y, command.m_color);
				}
			}
		break;

		default:
		break;
		}
	}
	std::cout << "Hebra finalizada\n";
}