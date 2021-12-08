%% Intro
%%Per usare selezionare solo la cartella con i file dentro
%%in output uscirà il mat con lo stesso nome della cartella dentro la
%%cartella stessa.
%%Non mettete altri file dentro la cartella grazie

clear
clc

% targetdir = uigetdir;
dir_list = dir; 
dir_names = {dir_list.name};
dir_names = dir_names([dir_list.isdir])
jj = 1; 

for ii = 1:length(dir_names)

name = [[dir_names{ii}], 'xx'];

if  all(name(1:3) == '202')   

   
targetdir = [dir_names{ii}]; 
[~,foldername,~] = fileparts(targetdir);
cd(targetdir)
list = ls;

if size(dir(fullfile(targetdir,'*.mat')),1)
    error('Già convertito coglione')
end

%% get signal names
signals = txtread(list(3,:));

signals_number = str2double(extractAfter(signals{4},'Signals: '));
n_elem = (repmat('%s',[1,signals_number]));

signals_names = extractAfter(signals{5},'names: ');
signals_names = erase(signals_names,',');
signals_names = textscan(signals_names,n_elem);

%% signals frequency
signals_frequency = str2double(extractAfter(signals{6},'[Hz]:'));

%% get signal timeseries
data = [];
n_elem = (repmat('%f',[1,signals_number]));
for k = 4 : size(list,1)
    fid  = fopen(list(k,:));
    data = [data;textscan(fid,n_elem)];
    fclose(fid);
end
data = cell2mat(data);

%% assign variable names
for k = 1 : length(signals_names)
varname = genvarname(string(signals_names{k}));
test_raw(jj).(varname) = data(:,k);
end
test_raw(jj).t = [0:1/signals_frequency:(size(data,1)-1)./signals_frequency]';
test_raw(jj).name = targetdir;


%% saving
jj = jj+1 
cd ..

end
end


%% functions    
function Rows = txtread(FileName)

    fid     = fopen(FileName);
    ii = 1;
    while ~feof(fid)
        textLineEntry = fgetl(fid);
        Rows{ii}   = textLineEntry;
        ii = ii + 1;
    end
    fclose(fid);

end