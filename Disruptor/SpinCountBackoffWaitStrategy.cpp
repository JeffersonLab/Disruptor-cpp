#include "stdafx.h"
#include "SpinCountBackoffWaitStrategy.h"
#include "BlockingWaitStrategy.h"

#include <ostream>
#include <iostream>

#include "ISequenceBarrier.h"
#include "Sequence.h"


namespace Disruptor
{

    SpinCountBackoffWaitStrategy::SpinCountBackoffWaitStrategy()
    {
        this->SPIN_TRIES = 10000;
        this->fallbackStrategy = std::make_shared< BlockingWaitStrategy >();
    }

    SpinCountBackoffWaitStrategy::SpinCountBackoffWaitStrategy(std::uint32_t spinTries,
                                                               std::shared_ptr<IWaitStrategy> fallbackStrategy)
    {
        this->SPIN_TRIES = spinTries;
        if (spinTries < 1) {
            this->SPIN_TRIES = 1;
        }

        this->fallbackStrategy = fallbackStrategy;
        if (fallbackStrategy == nullptr) {
            this->fallbackStrategy = std::make_shared< BlockingWaitStrategy >();
        }
    }


    std::int64_t SpinCountBackoffWaitStrategy::waitFor(std::int64_t sequence,
                                                       Sequence& cursor,
                                                       ISequence& dependentSequence,
                                                       ISequenceBarrier& barrier)
    {
        std::int64_t availableSequence;
        std::uint32_t counter = SPIN_TRIES;

        do {
            if ((availableSequence = dependentSequence.value()) >= sequence) {
                return availableSequence;
            }

            if (0 == --counter) {
                return fallbackStrategy->waitFor(sequence, cursor, dependentSequence, barrier);
            }
            //std::cout << " " <<  counter;
            barrier.checkAlert();
            //spinWait.spinOnce();

        } while (true);
    }

    void SpinCountBackoffWaitStrategy::signalAllWhenBlocking()
    {
        fallbackStrategy->signalAllWhenBlocking();
    }

    void SpinCountBackoffWaitStrategy::writeDescriptionTo(std::ostream& stream) const
    {
        stream << "SpinCountBackoffWaitStrategy";
    }


} // namespace Disruptor

