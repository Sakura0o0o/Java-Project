<template>
  <div v-if="isVisible" class="modal-overlay" @click.self="close">
    <div class="modal">
      <h3>新しい番組を追加 - {{ date }}</h3>

      <label>
        番組名:
        <input v-model="title" type="text" placeholder="番組名を入力" />
      </label>

      <label>
        詳細:
        <textarea v-model="description" placeholder="詳細情報を入力"></textarea>
      </label>

      <label>
        放送回:
        <input v-model.number="episode" type="number" min="1" />
      </label>

      <label>
        毎週繰り返す:
        <input type="checkbox" v-model="repeatWeekly" />
      </label>

     <label>
  カスタムカラー:
  <input type="color" v-model="color" />
</label>



      <label>
  放送開始時刻:
  <input type="time" v-model="startTime" />
</label>

<label>
  放送終了時刻:
  <input type="time" v-model="endTime" />
</label>


      <button @click="submit">追加</button>
      <button @click="close">キャンセル</button>
    </div>
  </div>
</template>

<script>
export default {
  props: {
    isVisible: Boolean,
    date: String
  },
  emits: ['update:isVisible', 'add-event'],
  data() {
    return {
      title: '',
      description: '',
      episode: 1,
      repeatWeekly: false,
      startTime: '19:00',
      endTime: '19:30',
      color: '#3498db'
    };
  },
  
  methods: {
    close() {
      this.$emit('update:isVisible', false);
    },
    submit() {
      if (!this.title.trim()) {
        alert('番組名は必須です！');
        return;
      }

      const baseDate = new Date(this.date);
      const events = [];

      for (let i = 0; i < (this.repeatWeekly ? 10 : 1); i++) {
        const date = new Date(baseDate);
        date.setDate(date.getDate() + i * 7);

        const startDateTime = `${date.toISOString().split('T')[0]}T${this.startTime}`;
	const endDateTime = `${date.toISOString().split('T')[0]}T${this.endTime}`;

        events.push({
          title: `${this.title} #${this.episode + i}`,
          start: startDateTime,
	  end: endDateTime,
	  color: this.color,
          extendedProps: {
            description: this.description,
            theme: '',
            sent: false,
            memo: ''
          }
        });
      }

      events.forEach(ev => this.$emit('add-event', ev));
      this.close();
    }
  }
};
</script>
