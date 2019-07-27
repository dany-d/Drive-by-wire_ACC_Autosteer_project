#ifndef fcan0_s32k14_rx_isr_h
#define fcan0_s32k14_rx_isr_h

extern flexcan_msgbuff_t canCom0_recvBuffFifo;
extern void fcan0_s32k14_rx_isr(uint8_t instance, flexcan_event_type_t eventType,
  uint32_t buffIdx, flexcan_state_t *flexcanState);

#endif
