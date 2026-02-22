import { useState } from 'react';
import { AMAL_TYPE, calculateWeight } from './utils/amalHeuristics';
import Header from './components/Header';
import StatsBar from './components/StatsBar';
import InputSection from './components/InputSection';
import FintechSection from './components/FintechSection';
import HistoryLog from './components/HistoryLog';

export default function App() {
  const [surgaPercentage, setSurgaPercentage] = useState(50);
  const [history, setHistory] = useState([]);
  const [description, setDescription] = useState('');

  const handleAddAmal = (type) => {
    if (!description.trim()) {
      alert("Deskripsi kegiatan tidak boleh kosong!");
      return;
    }

    const calculatedAmount = calculateWeight(description, type);

    let newPercentage = type === AMAL_TYPE.PAHALA 
      ? surgaPercentage + calculatedAmount 
      : surgaPercentage - calculatedAmount;
      
    newPercentage = Math.max(0, Math.min(100, newPercentage));

    setSurgaPercentage(newPercentage);

    const newRecord = {
      id: Date.now(),
      type,
      description,
      amount: calculatedAmount,
      time: new Date().toLocaleTimeString('id-ID', { hour: '2-digit', minute: '2-digit' })
    };

    setHistory([newRecord, ...history]);
    setDescription(''); 
  };

  const nerakaPercentage = 100 - surgaPercentage;

  return (
    <div className="w-full max-w-4xl bg-white border border-gray-200 rounded-xl shadow-sm mx-auto grid grid-cols-1 md:grid-cols-2 overflow-hidden">
      <div className="p-6 md:p-8 border-b md:border-b-0 md:border-r border-gray-200">
        <Header />
        <StatsBar 
          surgaPercentage={surgaPercentage} 
          nerakaPercentage={nerakaPercentage} 
        />
        <InputSection 
          description={description} 
          onDescriptionChange={setDescription} 
          onAddAmal={handleAddAmal} 
        />
      </div>
      <div className="p-6 md:p-8 bg-gray-50/50 flex flex-col gap-6">
        <FintechSection />
        <HistoryLog history={history} />
      </div>
    </div>
  );
}