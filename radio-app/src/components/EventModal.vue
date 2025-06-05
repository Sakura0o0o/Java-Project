<template>
  <div v-if="isVisible && event" class="modal-overlay" @click.self="close">
    <div class="modal">
      <h3>{{ event.title }}</h3>
      <p>{{ event.start }}</p>
      <p>{{ event.extendedProps.description }}</p>

      <label>
  メールテーマ:
  <textarea v-model="localTheme" rows="2" placeholder="メールのテーマを入力" tabindex="0"></textarea>
</label>

<div class="checkbox-group">
  <label class="checkbox-item">
    <input v-model="localSent" type="checkbox" />
    <span class="checkbox-label-text">送信済み</span>
  </label>
  <label class="checkbox-item">
    <input v-model="localWatched" type="checkbox" />
    <span class = "checkbox-label-text">視聴済み</span>
  </label>
</div>

<label>
  メモ:
  <textarea v-model="memo" placeholder="感想やメモを入力" tabindex="0"></textarea>
</label>



      <div class="buttons">
        <button @click="save">保存</button>
        <button @click="deleteEvent" class="danger">削除</button>
        <button @click="close">閉じる</button>
      </div>
    </div>
  </div>
</template>

<script>
export default {
  props: {
    isVisible: Boolean,
    event: Object
  },
  emits: ['update:isVisible', 'save', 'delete'],
  data() {
    return {
      localTheme: '',
      localSent: false,
      memo: '',
      localWathed: false
    };
  },
  watch: {
    event(newEvent) {
      if (newEvent?.extendedProps) {
        this.localTheme = newEvent.extendedProps.theme || '';
        this.localSent = newEvent.extendedProps.sent || false;
        this.memo = newEvent.extendedProps.memo || '';
	this.localWatched = newEvent.extendedProps.watched || false;
      }
    }
  },
  methods: {
    close() {
      this.$emit('update:isVisible', false);
    },
    save() {
      this.$emit('save', {
        theme: this.localTheme,
        sent: this.localSent,
        memo: this.memo,
	watched: this.localWatched
      });
      this.close();
    },
    deleteEvent() {
      if (confirm('このイベントを本当に削除しますか？')) {
        this.$emit('delete');
      }
    }
  }
};
</script>

<style scoped>
.modal-overlay {
  position: fixed;
  top: 0; left: 0; right: 0; bottom: 0;
  background: rgba(0,0,0,0.5);
  display: flex; justify-content: center; align-items: center;
  z-index: 1000;
}
.modal {
  background: white;
  padding: 20px;
  border-radius: 8px;
  width: 320px;
  z-index: 1001;
  position: relative;
}
label {
  display: block;
  margin-bottom: 10px;
}
input, textarea {
  width: 100%;
  box-sizing: border-box;
}
textarea {
  min-height: 80px;
}
.buttons {
  display: flex;
  justify-content: space-between;
  margin-top: 10px;
}
.danger {
  background-color: #e74c3c;
  color: white;
}

.checkbox-group {
  display: flex;
  align-items: center;
  justify-content: space-between;
  gap: 2px;            /* 間隔調整（必要に応じて） */
  margin-bottom: 10px;
}

.checkbox-item {
  align-items: center;
  gap: 0;
  margin: 0;
}

.checkbox-label-text {
  writing-mode: horizontal-tb !important;
  transform: none !important;
  direction: ltr !important;
  white-space: nowrap;
}



</style>
