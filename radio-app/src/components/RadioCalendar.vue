<template>
  <div>
    <div class = "calendar-wrapper">
    <FullCalendar ref="fullCalendar" :options="calendarOptions" />
    </div>

    <EventModal
      :isVisible="isModalVisible"
      :event="selectedEvent"
      @update:isVisible="isModalVisible = $event"
      @save="saveEventData"
      @delete="deleteEvent"
    />

    <AddEventModal
      :isVisible="isAddModalVisible"
      :date="newEventDate"
      @update:isVisible="isAddModalVisible = $event"
      @add-event="addEvent"
    />
  </div>
</template>

<script>
import FullCalendar from '@fullcalendar/vue3'
import dayGridPlugin from '@fullcalendar/daygrid'
import interactionPlugin from '@fullcalendar/interaction'
import EventModal from './EventModal.vue'
import AddEventModal from './AddEventModal.vue'
import timeGridPlugin from '@fullcalendar/timegrid';

export default {
  components: { FullCalendar, EventModal, AddEventModal },
  data() {
    return {
      isModalVisible: false,
      isAddModalVisible: false,
      selectedEvent: null,
      newEventDate: '',
      calendarOptions: {
        plugins: [dayGridPlugin, timeGridPlugin, interactionPlugin],
	initialView: 'timeGridWeek',
	slotMinTime: '06:00:00',
	slotMaxTime: '24:00:00',
        initialView: 'dayGridMonth',
	fixedWeekCount: false,
        events: [],
        eventClick: this.handleEventClick,
        dateClick: this.handleDateClick,
	eventDidMount: this.handleEventMount
      }
    }
  },
  methods: {
    handleEventMount(info){
     if(info.event.extendedProps.watched){
     info.el.style.opacity = '0.5';
     }
     },
    handleEventClick(info) {
      this.selectedEvent = info.event;
      this.isModalVisible = true;
      this.isAddModalVisible = false;
    },
    handleDateClick(info) {
      this.newEventDate = info.dateStr;
      this.isAddModalVisible = true;
      this.isModalVisible = false;
    },
    addEvent(newEvent) {
      const calendarApi = this.$refs.fullCalendar.getApi();
      calendarApi.addEvent(newEvent);
    },
    saveEventData(updatedData) {
      if (!this.selectedEvent) return;
      
      this.selectedEvent.setExtendedProp('theme', updatedData.theme);
      this.selectedEvent.setExtendedProp('sent', updatedData.sent);
      this.selectedEvent.setExtendedProp('memo', updatedData.memo);
      this.selectedEvent.setExtendedProp('watched',updatedData.watched);
      
      this.isModalVisible = false;
    },
    deleteEvent() {
      if (this.selectedEvent) {
        this.selectedEvent.remove();
        this.selectedEvent = null;
      }
      this.isModalVisible = false;
    }
  }
}
</script>

<style scoped>
.calendar-wrapper {
  width: 100vw;
  height: 70vh;
  margin: 0;
  padding: 0;
  box-sizing: border-box;
}

/* FullCalendarが親の高さを使えるように */
.calendar-wrapper :deep(.fc) {
  height: 100%;
}
</style>

